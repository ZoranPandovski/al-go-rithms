# Recurrent Neural Network (RNN)

![alt text](https://cdn-images-1.medium.com/max/1000/1*XB5c4rTCSeFQrK0aFC5IVw.png)

As per Wikipedia, a recurrent neural network (RNN) is a class of artificial neural network where connections between units form a directed graph along a sequence. This allows it to exhibit dynamic temporal behavior for a time sequence. Unlike feedforward neural networks, RNNs can use their internal state (memory) to process sequences of inputs. This makes them applicable to tasks such as unsegmented, connected handwriting recognition or speech recognition.

Recurrent Neural Network comes into the picture when any model needs context to be able to provide the output based on the input.

Sometimes the context is the single most important thing for the model to predict the most appropriate output.

Let’s understand this by an analogy. Suppose you are watching a movie, you keep watching the movie as at any point in time, you have the context because you have seen the movie until that point, then only you are able to relate everything correctly. It means that you remember everything that you have watched.

Similarly, RNN remembers everything. In other neural networks, all the inputs are independent of each other. But in RNN, all the inputs are related to each other. Let’s say you have to predict the next word in a given sentence, in that case, the relation among all the previous words helps in predicting the better output. The RNN remembers all these relations while training itself.

In order to achieve it, the RNN creates the networks with loops in them, which allows it to persist the information.

This loop structure allows the neural network to take the sequence of input. If you see the unrolled version, you will understand it better.

![alt text](https://cdn-images-1.medium.com/max/1000/1*NKhwsOYNUT5xU7Pyf6Znhg.png)

As you can see in the unrolled version. First, it takes the x(0) from the sequence of input and then it outputs h(0) which together with x(1) is the input for the next step. So, the h(0) and x(1) is the input for the next step. Similarly, h(1) from the next is the input with x(2) for the next step and so on. This way, it keeps remembering the context while training.

This way the RNN works.
