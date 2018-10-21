import numpy as np


def sigmoid(x):
    return 1/(1+ np.exp(-x))

def dsigmoid(x):
    return x * (1-x)

class NN:
    def __init__(self, x, y):
        self.neurons = 5
        self.x = x
        self.y = y
        self.err = 1
        self.w1 = np.random.random((x.shape[1], self.neurons))
        self.w2 = np.random.random((self.neurons, y.shape[1]))

    def forward(self):
        self.a1 = sigmoid(self.x @ self.w1)
        self.a2 = sigmoid(self.a1 @ self.w2)
        return self.a2

    def backprop(self):
        self.err = self.y - self.a2
        delta2 = self.a1.T @ self.err
        self.w2 += delta2
        delta1 = self.x.T @ ((self.err @ self.w2.T) * dsigmoid(self.a1))
        self.w1 += delta1

    def train(self):
        while abs(np.sum(self.err)) > 10e-5:
            #print("Error:", abs(np.sum(self.err)))
            self.forward()
            self.backprop()

    def predict(self, xx):
        self.x = xx
        return self.forward()

if __name__ == "__main__":
    network = NN(np.array([[0,0],[0,1],[1,0],[1,1]]).reshape(4, 2), np.array([1, 0, 0, 1]).reshape(4,1))
    network.train()
    print("Prediction 0.1,0.1: ", network.predict([0.1, 0.1]))
    print("Prediction 0.9,0.9: ", network.predict([0.9,0.9]))
    print("prediction 1,0.2: ", network.predict([1,0.2]))
    print("prediction 0,0.9:", network.predict([0,0.9]))
