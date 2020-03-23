# AI 时代

##### 2020/03/22

机器学习是什莫: 用已有的数据 来训练某种模型,利用此模型预测未来

机器学习Machine Learning 是人工智能的核心



机器学习  ====>数据为王 思想   (同时数据要多)   

机器学习要素  数据要多 数据要好  合适的算法  

 模型越准 预测的越精确

古人云 :  历史往往不一样,但历史总是惊人的相似	

特征工程  算法参数调优



机器学习 是一门交叉学科  

> > > 模式识别   == 机器学习
> > >
> > > 数据挖掘 ETL == 机器学习+数据库
> > >
> > > 计算机视觉 == 机器学习+图像处理
> > >
> > > 语音识别 == 机器学习+语音处理
> > >
> > > 统计学习  == 近似等于机器学习
> > >
> > > 自然语言处理 NLP  == 机器学习+文本处理



![](../../../img/AI/relation.png) 





人工智能 是一个很宽泛的概念

example :有监督的机器学习  预测人的健康状况  

![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?y%20%3D%20ax&plus;b)

w  为权重 

a 近似等于![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%7Bw_%7B0%7D%7D%5E%7B%7D) 

健康状况 y   预测的健康状况  ![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%5Chat%7By%7D)   (hat) 

 误差 ![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%5Cepsilon) =| ![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%5Chat%7By%7D)-  ![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?y)|  希望误差越小越好 



有监督机器学习 

![](../../../img/AI/supervised-learing.png)

训练集 (x ,y)   数据量大

 y = ax+b    将用户特征 与 权重w 相乘再相加 得到y 的预测值![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%5Chat%7By%7D)  ,与y 相减 的绝对值为 ![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%5Cepsilon)    得到![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%5Cepsilon)   来调整w  很多方法 可以调整w  就用一个常用的方法  梯度下降法 调整w  然后继续重试第一步,得到健康预测值 与真实值相减 得到误差 ![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%5Cepsilon)    比较前一次的误差  如果比之前大 则说明你调的方式是错误的 ,导致误差变大   如果比之前的小  说明误差在变小  继续按照这个方式  循环迭代 1>>>2 >>>3 直到 某一时刻 ![This is the rendered form of the equation. You can not edit this directly. Right click will give you the option to save the image, and in most browsers you can drag the image onto your desktop or another program.](http://latex.codecogs.com/gif.latex?%5Cepsilon) ,不变了 说明w  是最优解  是最好的模型 

有了这个最优解的之后  带入新数据 看看是否过拟合 之类的  就能达到预测未来



AI 用的较多的是python 语言 

scikit -learn 简单有效的预测数据分析工具每个人都可以访问，并且可以在各种上下文中重用基于NumPy、SciPy和matplotlib构建开源，商用-BSD许可证

scijit-learn  单机版 数据量不打的可以选择  海量数据的话可以选择 spark 的 mLlib  或者深度学习的tensflow   

> > > scikit-learn 分为以下模块 :
> > >
> > > classfication 分类 
> > >
> > > regression 回归 
> > >
> > > clusterubf  聚类
> > >
> > > dimensionality reduction 降维 
> > >
> > > model selection 模型选择
> > >
> > > preprocessing 预处理



数据量越大  考虑维度越多,,模型越精准  但是计算量也随之 越大  如何权衡 保证最大信息量的情况下 减少维度



特征转化 和归一化都属于 预处理的一部分



理解回归: 大自然让我们回归到一定的区间之内

线性: 两个变量之间存在一次方函数关系就称他们之间存在线性关系

线性: 线性linear 指量与量之间按比例.成直线的关系 ,在空间和事件上代表规则和光滑的运动



线性回归的本质 基于两个假设  :

1  假设数据 x y 程线性变化

2 假设数据服从一个正态分布



Normal-distribution  红色曲线为正态分布

![](../../../img/AI/Normal-distribution.png)



# ANN  

Artificial Neural Network  人工神经网络  

机器学习 浅层模型 相对应的是深度学习  深 

numpy  关于数学计算的库 

scipy 基于numpy 的物理方面的计算 傅里叶计算

Pandas是一个强大的分析结构化数据的工具集；它的使用基础是Numpy（提供高性能的矩阵运算）；用于数据挖掘和数据分析，同时也提供数据清洗功能。 突出一个数据  



