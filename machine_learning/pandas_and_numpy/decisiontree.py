
import pandas as pd
from pandas import DataFrame
df_Tennis = pd.read_csv(r"C:\Users\Desktop\DATA_SET\weather.csv")

df_Tennis

def Entropy(probs):
    import math
    return sum([-prob*math.log(prob,2) for prob in probs])

def Entropy_of_list(a_list):
    from collections import Counter
    cnt = Counter(x for x in a_list)
    print("No and Yes classes:",a_list.name,cnt)
    num_ins = len(a_list)*1.0
    probs = [x/num_ins for x in cnt.values()]
    return Entropy(probs)
total_entropy = Entropy_of_list(df_Tennis['play'])
total_entropy

def information_gain(df,split_attr_name,target_attr_name,trace=0):
    df_split = df.groupby(split_attr_name)
    for name,group in df_split:
        nobs = len(df.index)*1.0
        df_aggregate_ent = df_split.agg({target_attr_name:[Entropy_of_list,lambda x:len(x)/nobs]})
        df_aggregate_ent.columns = ['Entropy','properObservation']
        new_entr = sum(df_aggregate_ent['Entropy']*df_aggregate_ent['properObservation'])
        old_entr = Entropy_of_list(df[target_attr_name])
        return old_entr - new_entr
print('info gain of outlook is:'+str(information_gain(df_Tennis, 'outlook', 'play')),"\n")
print('info gain of temperature is:'+str(information_gain(df_Tennis, 'temperature', 'play')),"\n")
print('info gain of wind is:'+str(information_gain(df_Tennis, 'wind', 'play')),"\n")
print('info gain of humidity is:'+str(information_gain(df_Tennis, 'humidity', 'play')),"\n")

def id3(df,target_attr_name,attr_name,default_class = None):
    from collections import Counter
    cnt = Counter(x for x in df[target_attr_name])
    
    if len(cnt) == 1:
        return next(iter(cnt))
    elif df.empty or (not attr_name):
        return default_class
    else:
        gainz = [information_gain(df,attr,target_attr_name) for attr in attr_name]
        index_of_max = gainz.index(max(gainz))
        best_attr = attr_name[index_of_max]
        tree = {best_attr:{}}
        remaining_attr = [i for i in attr_name if i != best_attr]
        for attr_val, data_subset in df.groupby(best_attr):
            subtree = id3(data_subset,target_attr_name,remaining_attr,default_class)
            tree[best_attr][attr_val] = subtree
        return tree

attr_names = list(df_Tennis.columns)
print(attr_names)

attr_names.remove('play')
attr_names.remove('id')
print(attr_names)

from pprint import pprint
tree = id3(df_Tennis,'play',attr_names)
print("Final Decision Tree:\n")
pprint(tree)

