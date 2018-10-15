import numpy as np
import pandas as pd
import tensorflow as tf
import datetime
from sklearn.model_selection import train_test_split

def logistic_regression(x_full, y_full, n_features, epochs, learning_rate, batch_size):

    x_train, x_test, y_train, y_test = train_test_split(x_full, y_full, test_size=0.25)

    X = tf.placeholder(tf.float32, [None, n_features], name="input")
    y = tf.placeholder(tf.float32, [None, 1], name="output")

    w = tf.Variable(tf.random_normal([n_features, 1], stddev=0.03), name="weights")
    b = tf.Variable(tf.random_normal([1]), name="bias")

    logistic = tf.exp(-tf.add(tf.matmul(X, w), b))
    y_model = 1/ (1 + logistic)
    epsilon = 1e-7
    cost = -tf.reduce_mean(y*tf.log(y_model + epsilon) + (1-y)*tf.log(1-y_model + epsilon))

    training = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)
    cost_summary = tf.summary.scalar('cost', cost)

    init_op = tf.global_variables_initializer()
    total_batch = int(len(y_train)/ batch_size)

    now = datetime.datetime.now().strftime("%I_%M")
    writer = tf.summary.FileWriter(f"logs/run-{now}", tf.get_default_graph())

    with tf.Session() as sess:
        sess.run(init_op)
        sess.run(tf.local_variables_initializer())

        for epoch in range(epochs):
            avg_cost = 0
            for iterator in range(total_batch):
                start_point = iterator * batch_size
                x_batch = x_train[start_point: start_point + batch_size ]
                y_batch = y_train[start_point: start_point + batch_size ]

                summary_str = sess.run(cost_summary, feed_dict={X: x_batch, y: y_batch})
                step =  epoch* total_batch + iterator
                writer.add_summary(summary_str, step)

                _, cost_val = sess.run([training, cost], feed_dict = {X : x_batch, y : y_batch})
                avg_cost += cost_val/total_batch

            saver = tf.train.Saver({"weights" : w, "bias" : b})
            print(f'Epoch {epoch + 1}, cost = {avg_cost}, step = {epoch*total_batch + iterator}')

        writer.close()
        ret_value = y_model.eval(feed_dict = {X : x_test})
    return ret_value
