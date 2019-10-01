import numpy as np

def euclidean(x,y):
    return np.sqrt(np.sum((x-y)**2))

class LVQClassifier():
    '''Classifier for the LVQ Algorithm'''
    def __init__(self, score_func, eta = 0.2):
        # function to use for finding
        # distance to neurons
        self.score = score_func

        # η, learning rate
        self.eta = eta
            
        # used to make unique labels from
        # train set, can be ignored
        self.unique_labels = {}
        self.label_counter = 0
    
    def register_labels(self,labels):
        '''
        Used to make unique labels from
        train set, can be ignored
        '''
        for label in labels:
            if label not in self.unique_labels:
                self.unique_labels[label] = self.label_counter
                self.label_counter += 1
    
    
    def train(self,train,labels,epochs = 5):
        '''Train classifier with train set, labels for train set and set amount of epochs.
        Neural net has as many neurons as there are classes.

        Process is:
        1)Initialize neuron weights randomly
        2)For every sample:
            2.1) Find weight with smallest distance from sample
            2.2) If neuron class is the same as the sample class,
            add the quantity η*(sample - winner_weight) to the winner weight,
            else subtract it
        A rounding step is added to avoid floating point overflow errors.'''
        # for empty train set, do nothing
        if  train.size == 0 or labels.size == 0:
            return
        # make labels
        self.register_labels(labels)
        
        # initialize neuron weights randomly
        self.weights = np.array([np.random.uniform(low = 0, high = 1, size = len(train[0]) )  for _ in range(len(self.unique_labels))])
        
        
        for i in range(epochs):
            # for every epoch, sample in train set
            for i,sample in enumerate(train):
                # calculate sample distance to neurons
                scores = np.array([self.score(weight,sample) for weight in self.weights ])
                # find neuron with smallest distance from sample
                winner = np.argmin(scores)

                # if neuron label matches sample label
                # increase weight (reward)
                if self.unique_labels[labels[i]] == winner:
                    self.weights[winner] += self.eta*(sample - self.weights[winner] )
                # else decrease weight (penalty)
                else:
                    self.weights[winner] -= self.eta*(sample - self.weights[winner] )

                # apply rounding for numeric stability
                # eliminates overflow errors
                # not part of the algorithm
                round_func = lambda weight: np.apply_along_axis(np.round,0,weight,8)
                self.weights = np.apply_along_axis(round_func,0,self.weights)
                
           
    def predict(self,sample):
        '''
        find neuron with smallest distance from sample
        '''
        scores = np.array([self.score(weight,sample) for weight in self.weights ])

        return np.argmin(scores)
        
            
        
        
        
a = LVQClassifier(euclidean, eta = 0.1)

train = []
labels = []

for i in range(0,1000):
    # should be class 0
    train.append([1,0,0,0])
    # should be class 1
    train.append([1,0,0,1])
    # should be class 2
    train.append([1,0,1,1])
    
    # assign classes
    labels.append(0)
    labels.append(1)
    labels.append(2)

train = np.array(train)
labels = np.array(labels)
    
    

# train with train set
a.train(train,labels)


print(a.weights)

# should print
# 0
# 1
# 2
b = [1,0,0,0]
print(a.predict(b))
b = [1,0,0,1]
print(a.predict(b))
b = [1,0,1,1]
print(a.predict(b))