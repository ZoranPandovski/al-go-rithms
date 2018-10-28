# Transfer Learning
In Transfer Learning, the knowledge of an already trained Machine Learning model is applied to a different but related problem. For
example, if you trained a simple classifier to predict whether an image contains a backpack, you could use the knowledge that the 
model gained during its training to recognize other objects like sunglasses. With transfer learning, we basically try to exploit 
what has been learned in one task to improve generalization in another. We transfer the weights that a Network has learned at Task 
A to a new Task B.<br>
The general idea is to use knowledge, that a model has learned from a task where a lot of labeled training data is available, in a 
new task where we don’t have a lot of data. Instead of starting the learning process from scratch, you start from patterns that 
have been learned from solving a related task. Transfer Learning is mostly used in Computer Vision and Natural Language Processing 
Tasks like Sentiment Analysis, because of the huge amount of computational power that is needed for them.
![alt workflow](https://github.com/BAJUKA/al-go-rithms/blob/master/deep_learning/python/transfer-learning/image/transfer-learning.jpeg)
