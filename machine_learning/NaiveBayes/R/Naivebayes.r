library(class)
nb<-naiveBayes(Species~.,iris)
table(predict(nb,iris[,-5]),iris[,5])
pairs(iris[1:4],main="Iris Data (red=setosa,green=versicolor,blue=virginica)",pch=21, bg= c("red", "green3", "blue")[unclass(iris$Species)])
n=dim(iris)[1]
index=sample(n,0.7*n)
appren=iris[index,]
test=iris[-index,]
nb.model <- naiveBayes(Species~.,data=appren)
pred=predict(object=nb.model,newdata=test)
test.mod<-cbind(test,pred)
head(test.mod,5)
confusion=table(test.mod$Species,test.mod$pred)
round(prop.table(confusion),2)
