from keras.models import Sequential
from keras.layers import Dense,Dropout,LSTM,Activation

def rnn_model(input_shape):
    model = Sequential()
    model.add(Dense(32, input_dim=input_shape))
    model.add(Activation('relu'))
    model.add(LSTM(64))
    model.add(Dropout(0.5))
    model.add(Dense(1))
    model.add(Activation('sigmoid'))
    model.compile(loss='binary_crossentropy', optimizer='rmsprop')

def rnn_model_fit(model,x,y,batch_size,epoch):
    model.fit(x,y,batch_size,epoch)

def rnn_predict(model,x):
    y_pred=model.predict(x)
    return y_pred