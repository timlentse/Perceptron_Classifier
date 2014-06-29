## Perceptron_Classifier

**傅里叶描绘子的生成**

把图像边界坐标点看作复数，对复数序列作DFT，DFT结果就是傅里叶描绘子，保留部分描绘子，可以对原图的边界较好的复原

click [here](https://github.com/timlentse/Perceptron_Classifier/blob/master/pdf.pdf) for more informations
### 原图边界

#### Plane1:                                                  
 
![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/50descriptor%20plane1.png)

#### Plane2: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/50descriptor%20plane2.png)

### 10个傅里叶描绘子重建

#### Plane1: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/10descriptor%20plane1.png)

#### Plane2: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/10descriptor%20plane2.png)

### 18个傅里叶描绘子重建

#### Plane1: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/18descriptor%20plane1.png)

#### Plane2: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/18descriptor%20plane2.png)

### 20个傅里叶描绘子重建

#### Plane1: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/20descriptor%20plane1.png)

#### Plane2: 

![alt tag](https://raw.githubusercontent.com/timlentse/Perceptron_Classifier/master/20descriptor%20plane2.png)

通过不断的尝试以及比较，我个人认为保证边界能够被辨识的最短描绘子的长度为17。基于上面傅里叶描绘子生成训练集测试集，求出W。
