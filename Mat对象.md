# OpenCV中的Mat对象   
## Mat   
&nbsp; Mat是Matrix的缩写。在计算机内存中，图像是以矩阵的形式存储和处理的   
&nbsp; 早期的opencv是用C语言编写的，其提供的接口也是C语言的接口，这时的图像运算的基本结构也是iplImage（Intel image progressing library）的结构体   
&nbsp; 而随着C++的发展，opencv的编写也引入了这种面向对象的编程思想，讲大量的源码用C++重写。为图像的存储和处理引入了一个名为Mat（Matrix）的封装类。由于C++高级编程性的特性，Mat的功能远超原始的iplImage，并且在之后的发展中不断地对Mat类进行拓展，使其几乎囊括了计算机视觉中对图像处理的各种基本要求 &nbsp; ~~C++天下第一!~~   
## Mat的构造函数   
~~~
 Mat();   //默认构造参数 
~~~
~~~
Mat (const Mat &m);  //拷贝构造函数
~~~
~~~
Mat(int rows,  int cols,  int type);  
//行数，列数，数据结构参数
//rows和cols可换成Size(rows, cols)
//进而构造函数变为：Mat (Size size,  int type);
//数据结构参数类型：
//unsigned 8 bits : CV_8UC%
//unsigned 32 bits (float) : CV_32FC%
//unsigned 64 bits (double) : CV_64FC%
//C后面的%是一个数字，表示通道数
//例如：RGB色彩空间就是CV_8UC3
~~~
~~~
Mat (int rows, int cols, int type, const Scalar &s)
//Scalar(, , ...)用于初始化
//参数个数对应通道数
//每个参数对应每个通道的具体数值
~~~
Mat的构造函数好有很多，这里介绍的是最常用的几种，其他的构造函数参考：[Mat对象的构造函数](https://docs.opencv.org/3.2.0/df/dfc/classcv_1_1Mat__.html)
## Mat对象的初始化   
### 通过imread初始化
~~~
Mat src = imread("   ");
//引号内放入图片地址
~~~
### 通过create初始化
~~~
Mat src;
if(src.empty()){
	src.create(Size size, VC_8UC3);
}
~~~