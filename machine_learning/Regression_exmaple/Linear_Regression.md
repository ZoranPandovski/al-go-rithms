# Linear Regression

**Linear regression** is a type of supervised machine learning that is used to fit and build predictive models for **continuous** or **non-discrete** values.

The aim of a linear regression model is to "fit" the data linearly i.e. it values can be predicted using straight line geometry.

The model is trained using a dataset which contains the correct output for every instance of the dataset. The commonly used method for dividing the dataset into training and testing parts is
**hold-out cross validation**, where one part is "held" as the training part and the other as the testing part. Common **training:testing** ratios used are **60:40** and **80:20**,
although any ratio can be used.

For linear regression, the aim of the model while training is to minimize the **cost function**, which is given by:

**J = 1/2[(h - y)^2]**

where **h** is called the hypothesis of the model. For a dataset with **two** input parameters, **h** can be given as:

**h = w0 + w1(x1) + w2(x2)**

where **w1** and **w2** are the weights associated with the input parameters. **w0** is added to create a **bias**.This can be extended to any number of input parameters.

The optimal weights are calculate by repeatedly calculating and minimizing **J**. The optimal values are obtained when **J** reaches it's minimum value. The weights are updated after every iteration using the update rule:

**w = w - alpha(dJ/dw)**

where **dJ/dw** is described as the **partial differentiation** of **J** with respect to the corresponding weights. So for **w1**, it is the partial differentiation with respect to **w1** and for **w2**, with respect to **w2**. The term **alpha** is called the **learning rate** of the model and takes values from  **0-1**. A **lower alpha** would make the model **more accurate but slower**. A **higher alpha** would make the model **faster, but would decrease accuracy**. Take a big enough **alpha** and it is possible that **J** will never approach it's minimum.
