#include "MyFunction.h"

int main(int argc, char *argv[] )
{
    Mat src1 ,src2;
    if( argc !=3 || !(src1=imread(argv[1], 0)).data || !(src2=imread(argv[2],0)).data)
           return -1;

    Mat FDsor1 = Mat::zeros(Size (src1.cols, src1.rows),src1.type());
    Mat FDsor2 = Mat::zeros(src2.rows, src2.cols ,src2.type());

    Point b0(0,0);     int rev;
    cout<<"Now input reserve = ";
    cin >> rev ;

   complexVector boundary ,output1,output2;

 //图一的模式生成
    FrDstor::Findbegin(src1, b0);  
    FrDstor::Iterator(src1 , boundary , b0);

    FrDstor::Fourier(boundary ,output1);
    complexVector FT1(output1);
    Mat descriptors1 =  Mat::zeros(1,rev,CV_32F);
    FrDstor::idFourier(FT1,descriptors1, rev);
    FrDstor::reconstruct(FT1 ,FDsor1);
    imshow ("reconstruct1",FDsor1);


 // 图二的模式生成
    FrDstor::Findbegin(src2, b0);
    FrDstor::Iterator(src2 , boundary , b0);
    FrDstor::Fourier(boundary ,output2);

    complexVector FT2(output2);
    Mat descriptors2 =  Mat::zeros(1,rev,CV_32F);
    FrDstor::idFourier(FT2, descriptors2, rev);
    FrDstor::reconstruct(FT2 ,FDsor2);
    imshow ("reconstruct2",FDsor2);

 //感知机分类器
    Mat W= Mat::zeros(1,rev,CV_32F);
    for (int i(0); i<100;i++) {
    Classifier::Perceptron_Classifier(descriptors1, W ,1);
    Classifier::Perceptron_Classifier(descriptors2, W ,1); }
    cout <<"the w="<<endl<< W<< endl;
    waitKey(0);
    return 0;
}
