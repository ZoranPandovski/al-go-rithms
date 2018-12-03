import random
import numpy as np
FEATURE = 5
def sign(num):
    if np.sign(num) <= 0:
        return -1.0
    return 1.0
def pla(X,y,m):
    ''' improved (pocket) perceptron learning algorithm

    Arguments:
        X {numpy array or numpy matrix}
        y {numpy array or numpy matrix} -- target
        m {integer} -- the size of training dataset

    Returns:
        list or numpy array -- updated weight
    '''

    random.seed()
    flag = True
    pw = np.zeros((1,FEATURE+1))
    random_set = list(range(m))
    random.shuffle(random_set)
    iteration = 0
    while flag:
        flag = False
        for n in random_set:
            w = np.copy(pw + X[n]*y[n])
            total = 0
            correct = 0
            error = 0
            for i in range(m):
                total += pw*X[i].T
                correct += w*X[i].T
                if y[i] != sign(total.sum()):
                    error += 1
                if y[i] != sign(correct.sum()):
                    error -= 1
            if error < 0:
                pw = np.copy(w)
            iteration+=1
    return pw
