import numpy as np
import pandas as pd
from keras.layers import Input, Dense, Bidirectional, Embedding, Dropout, Flatten
from keras.layers import concatenate, SpatialDropout1D, GlobalAveragePooling1D, GlobalMaxPooling1D
from keras.layers.convolutional import Conv1D
from keras.layers.convolutional import MaxPooling1D
from keras.models import Model
from sklearn.model_selection import train_test_split
from utils import *


maxlen = 150
max_features = 2500


gop = pd.read_csv('Data/gop.csv')
data = gop[['text','sentiment']]

# Balance Negative - Positive tweets
data[data['sentiment'] == 'Negative'] = data[data['sentiment'] == 'Negative'][:2236]
data = data.dropna()

data['sentiment'].value_counts() #Negative: 8493; Neutral: 3142; Positive: 2236
X, Y = format_data(data, max_features, maxlen)
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.25, random_state=42)


# Input shape
inp = Input(shape=(maxlen,))

# Embedding and CNN
x = Embedding(max_features, 150)(inp)
x = SpatialDropout1D(0.25)(x)
x = Conv1D(filters=32, kernel_size=3, padding='same', activation='relu')(x)
x = MaxPooling1D(pool_size=2)(x)
x = Conv1D(filters=16, kernel_size=5, padding='same', activation='relu')(x)
x = MaxPooling1D(pool_size=4)(x)
x = Flatten()(x)

# Output layer
output = Dense(1, activation='sigmoid')(x)

model = Model(inputs=inp, outputs=output)
model.compile(loss='binary_crossentropy', optimizer='adam', metrics=['accuracy'])


model.fit(X_train, Y_train, epochs=5, batch_size=32, verbose=1)

results = model.predict(X_test, batch_size=1, verbose=1)
run_test(results, Y_test)
