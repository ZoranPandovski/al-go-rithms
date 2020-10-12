import numpy as np
def mse(observation,predicted):
    m1,n1 = observation.shape
    m2,n2 = predicted.shape
    assert m1 == m2, "different number of examples"
    assert n1 == n2, "different number of features"
    return np.mean(np.square(observation-predicted))
