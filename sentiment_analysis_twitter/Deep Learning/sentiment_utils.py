import pandas as pd
import numpy as np
from keras.preprocessing.text import Tokenizer
from keras.preprocessing.sequence import pad_sequences



def format_data(data, max_features, maxlen):
    data = data[data.sentiment != "Neutral"]
    data = data.sample(frac=1).reset_index(drop=True)
    data['text'] = data['text'].apply(lambda x: x.lower())

    Y = to_numerical(data['sentiment'].values) # 0: Negative; 1: Positive
    X = data['text']

    remove_rt_url(X)

    tokenizer = Tokenizer(num_words=max_features)
    tokenizer.fit_on_texts(list(X))

    X = tokenizer.texts_to_sequences(X)
    X = pad_sequences(X, maxlen=maxlen)

    return X, Y


def to_numerical(d):
    """Converts the categorical df[col] to numerical"""
    _, d = np.unique(d, return_inverse=True)
    return d


def run_test(results, Y_validate):
    pos_correct, neg_correct, total_correct = 0, 0, 0
    _, (neg_count, pos_count) = np.unique(Y_validate, return_counts=True)

    for i, r in enumerate(results):
        if r > 0.5:
            r = 1
        else:
            r = 0

        if r == Y_validate[i]:
            total_correct += 1
            if r == 0:
                neg_correct += 1
            else:
                pos_correct += 1


    print('Positive Accuracy:', pos_correct/pos_count * 100, '%')
    print('Negative Accuracy:', neg_correct/neg_count * 100, '%')
    print('Total Accuracy:', total_correct/(pos_count + neg_count) * 100, '%')


def remove_rt_url(df):
    url = r'((https?):((//)|(\\\\))+([\w\d:#@%/;$()~_?\+-=\\\.&](#!)?)*)'
    df.replace(regex=True, inplace=True, to_replace=r'^RT ', value=r'')
    df.replace(regex=True, inplace=True, to_replace=url, value=r'')