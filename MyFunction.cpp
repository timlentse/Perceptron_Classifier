#include "MyFunction.h"

typedef  unsigned int unit ;


void FrDstor::Findbegin(const Mat &src, Point &b0){

   for (int i(0); i<src.rows; ++i) {
       for (int j(0);j<src.cols;++j) {
        const  uchar* p = src.ptr<uchar>(i);
        if (p[j]==0) {
            b0.x=j;
            b0.y=i;
            return;
        }
     }
  }
}

// Find contours
void FrDstor::Iterator(const Mat &src ,complexVector &boundary, Point &b0) {
    boundary.clear();
    Point ck_1, next ,ck(b0) ,bk(b0);
    complex<float> acomplex(b0.x ,b0.y);
    boundary.push_back (acomplex);
    --ck.x;
    do
    {
       do
        {
            if (ck.y<bk.y&&ck.x==bk.x){
                next.y=ck.y;
                next.x=ck.x+1;  }
            else if (ck.y<bk.y&&ck.x>bk.x){
                next.y=ck.y+1;
                next.x=ck.x;
            }
            else if (ck.y==bk.y&&ck.x>bk.x){
                next.y=ck.y+1;
                next.x=ck.x ;
            }
            else if (ck.y>bk.y&&ck.x>bk.x){
                next.y=ck.y;
                next.x=ck.x-1;
            }
            else if (ck.y>bk.y&&ck.x==bk.x){
                next.y=ck.y;
                next.x=ck.x-1;
            }
            else if (ck.y>bk.y&&ck.x<bk.x){
                next.y=ck.y-1;
                next.x=ck.x;
            }
            else if (ck.y==bk.y&&ck.x<bk.x){
                next.y=ck.y-1;
                next.x=ck.x;
            }
            else if (ck.y<bk.y&&ck.x<bk.x){
                next.x=ck.x+1;
                next.y=ck.y;
            }
            if (src.at<uchar>(ck)==0){
                acomplex.real(ck.x);
                acomplex.imag(ck.y);
                boundary.push_back(acomplex);
                 bk =ck;}
            else {  ck_1=ck;
                    ck=next;}
        }
       while (bk!=ck);
       ck=ck_1;
        }
     while(b0!=bk);
     return ;
}

//DFT
void FrDstor::Fourier(const complexVector &boundary, complexVector &output){

   for (unit u(0); u<boundary.size(); ++u)
          {
           complex<float> au;
             for (uint k(0); k<boundary.size(); ++k) {
             {
           complex<float> powder(0,-M_PI*2*k*u/boundary.size());
           complex<float> ep = exp(powder);
                au +=boundary.at(k)*ep;
             }
           }
      output.push_back(au);
         }
}
//IDFT
void  FrDstor::idFourier(complexVector &DFT_Result ,Mat& descriptors, int P) {
    uint k=0; complexVector temp;
    Mat_<float>::iterator iter= descriptors.begin<float>();
    while(k<DFT_Result.size())
           {
            complex<float> sk;
              for (uint u(0); u<DFT_Result.size(); ++u) {
                  if (u<P/2 || u>DFT_Result.size()-P/2-1)
              {
            float it= 0.0;
            magnitude(&DFT_Result.at(u).real(),&DFT_Result.at(u).imag(),&it,1);
            *iter=it;
            iter++;
            complex<float> powder(0,M_PI*2*k*u/DFT_Result.size());
            complex<float> ep =exp(powder);
                 sk += DFT_Result.at(u)*ep;
              }
            }
              sk /= DFT_Result.size();
              temp.push_back(sk);
              ++k;
          }
     DFT_Result= temp;
     return ;
}


// 选取部分傅立叶描绘子重建边界
void FrDstor::reconstruct(const complexVector &iDFT_Result, Mat &dst){
    Point po;
          for (unit k(0); k<iDFT_Result.size(); ++k){
              po.x = floor(iDFT_Result.at(k).real());
              po.y = floor(iDFT_Result.at(k).imag());
              dst.at<uchar>(po) = 255;
          }
   return ;
}


//训练集生成
void Classifier::Perceptron_Classifier( Mat&descriptors, Mat& w, bool flag){

  RNG rng;  float a (0);
  Mat noise = Mat::zeros(descriptors.rows, descriptors.cols ,CV_32F);
  double sigma = 0.0;
  minMaxIdx(descriptors, 0, &sigma);
  sigma /=10;
  for (int i(0); i<100; ++i) {
  rng.fill(noise,RNG::NORMAL, 0, sigma);
  add(noise, descriptors, noise);
  for (int j(0);j<noise.cols; ++j){
     a += noise.at<float>(0,j)*w.at<float>(0,j);
  }
  if (a <= 0)  {
      add(noise,w,w) ;}
           }
  }
