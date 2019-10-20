#KNN Regressor Function
knn <- function(train.data, train.label, test.data, K){
  
  train.len <- nrow(train.data)
  test.len <- nrow(test.data)
  pred.label <- data.frame()
  dist <- as.matrix(dist(rbind(test.data, train.data), method= 'euclidean'))[1:test.len, (test.len+1):(test.len+train.len)]
  
  for (i in 1:test.len){
    ### ...find its K nearest neighbours from training sampels...
    nn <- as.data.frame(sort(dist[i,], index.return = TRUE))[1:K,2]
    
    ###... and calculate the predicted labels according to the majority vote
    pred.label[i,1]<- mean(train.label[nn,])
  }
  return(pred.label)
}

#Predicting by calling the model
data(mtcars)

## Splitting the data into train and test with train having 80%
smp_size <- floor(0.8 * nrow(mtcars))

#Creating the train index
train_ind <- sample(seq_len(nrow(mtcars)), size = smp_size)

#Splitting the data into train and test
train <- mtcars[train_ind, ]
test <- mtcars[-train_ind, ]

#Splitting the columns into x and y for train and test
train.x <- train[,c(2,3,4)]
train.y <- train[,1,drop=FALSE]

test.x <- test[,c(2,3,4)]
test.y <- test[,1,drop=FALSE]

pred.y <- knn(train.x, train.y, test.x,5)

#Finding the mean square error
mse <- mean((pred.y - test.y)^2)
mse
