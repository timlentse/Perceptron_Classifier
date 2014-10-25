## Perceptron_Classifier

**傅里叶描绘子的生成**

如果把图像边界像素坐标点`（i，j）`看作复数，对复数序列作DFT，DFT结果一定程度上描述了边界信息，我们把DFT的结果叫做傅里叶
描绘子，保留部分描绘子，可以对原图的边界较好的复原。
Click [Here](https://github.com/timlentse/Perceptron_Classifier/blob/master/pdf.pdf) for more informations
****
### Below are screen shots in my ubuntu

####Plane1:
![orignal plane1](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/50descriptor%20plane1.png)

####Plane2: 

![orignal plane2g](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/50descriptor%20plane2.png)

### 10个傅里叶描绘子重建

####Plane1: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/10descriptor%20plane1.png)

####Plane2: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/10descriptor%20plane2.png)

### 18个傅里叶描绘子重建

####Plane1: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/18descriptor%20plane1.png)

####Plane2: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/18descriptor%20plane2.png)

### 20个傅里叶描绘子重建

####Plane1: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/20descriptor%20plane1.png)

####Plane2: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/20descriptor%20plane2.png)

我们通过不断选取不同的保留值观察重建效果，对于这幅两幅图来说，我的结论是保证边界能够被辨识的最短描绘子的长度为17。基于上面傅里叶描绘子生成训练集测试集，可求出W。
