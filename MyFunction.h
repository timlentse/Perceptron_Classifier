#ifndef MYFUNCTION_H
#define MYFUNCTION_H
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <complex.h>
#include <math.h>
#include <vector>
#include <iostream>
using namespace cv;
using namespace std;
typedef vector<complex<float> > complexVector ;
typedef vector <double> vd;
namespace FrDstor {

   void Findbegin(const Mat &src, Point &b0);
   void Fourier(const complexVector &boundary, complexVector &output);
   void idFourier(complexVector &DFT_Result ,Mat & descriptors, int P);
   void reconstruct(const complexVector &iDFT_Result, Mat &dst) ;
   void Iterator(const Mat &src ,complexVector &boundary, Point &b0) ;

}

namespace Classifier {

void Perceptron_Classifier( Mat &de, Mat& w, bool flag);
}

#endif // MYFUNCTION_H
