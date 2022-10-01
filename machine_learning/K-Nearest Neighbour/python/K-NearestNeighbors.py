import numpy as np
import pandas as pd
import random
from math import sqrt
from collections import Counter
import warnings # to warn user on using a dumb number for k


def k_nearest_neighbors(data,predict,k=3):
    if(len(data))>=k:
        warnings.warn('K is set a value less than total voting groups')
    distances=[]
    for group in data:
        for features in data[group]:
            # 1. euclidean_distance=sqrt( (features[0]-predict[0])**2 + (features[1]-predict[1])**2 )
            # this is hard coded for only two dimensions, so we'll use numpy instead of the above formula as it is faster
            # 2. euclidean_distance=np.sqrt(np.sum((np.array(features)-np.array(predict))**2))
            # even simpler version than the above one is 
            euclidean_distance=np.linalg.norm(np.array(features)-np.array(predict))
            distances.append([euclidean_distance,group]) # add [euclidean_distance, group] to distances 
    #for i in sorted(distances[:k]):
    #    i[i]
    #instead
    votes=[i[1] for i in sorted(distances)[:k]]
    votes_result=Counter(votes).most_common(1)[0][0] # as we only care about the one most common vote
    confidence=Counter(votes).most_common(1)[0][1] / k # how many / k
    
    return votes_result,confidence
accuracies=[]
for i in range(25):
    df=pd.read_csv("breast-cancer-wisconsin-data.csv") # reads the csv in df
    df.replace('?',-9999,inplace=True) # handle errorneous values
    df.drop(['id'],1,inplace=True) # not useful
    full_data=df.astype(float).values.tolist() # every value in the dataset ought to be a float 
    random.shuffle(full_data) # just to shuffle the dataset
    
    # our version of train_test_split
    test_size=0.2
    train_set={2:[],4:[]}
    test_set={2:[],4:[]}
    train_data=full_data[:-int(test_size*len(full_data))]
    test_data=full_data[-int(test_size*len(full_data)):]
    
    for i in train_data:
        train_set[i[-1]].append(i[:-1])
        
    for i in test_data:
        test_set[i[-1]].append(i[:-1])    
        
    correct=0
    total=0
    
    for group in test_set:
        for data in test_set[group]:
            vote,confidence=k_nearest_neighbors(train_set,data,k=5)
            if group==vote: # if the prediction is correct
                correct=correct+1 
            # else:
               # print(confidence) # confidence scores for incorrect votes
            total=total+1
    
    #print('Accuracy: ',correct/total)
accuracies.append(correct/total)
print(sum(accuracies)/len(accuracies))

# HIGHEST ACCURACY OBTAINED = 99.28% in 25 epochs
