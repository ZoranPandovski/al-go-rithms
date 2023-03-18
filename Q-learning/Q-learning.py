import numpy as np

# Q-learning function
def q_learning(env, learning_rate=0.1, discount_factor=0.9, epsilon=0.1, num_episodes=1000):
    # Initialize Q-table with zeros
    Q = np.zeros((env.observation_space.n, env.action_space.n))

    # Iterate over episodes
    for episode in range(num_episodes):
        # Reset the environment for each episode
        state = env.reset()
        done = False

        # Iterate over timesteps
        while not done:
            # Choose action using epsilon-greedy strategy
            if np.random.uniform(0, 1) < epsilon:
                action = env.action_space.sample()  # Exploration
            else:
                action = np.argmax(Q[state, :])    # Exploitation

            # Take the chosen action and observe the reward and new state
            next_state, reward, done, info = env.step(action)

            # Update Q-value of the current state-action pair
            Q[state, action] = Q[state, action] + learning_rate * \
                (reward + discount_factor * np.max(Q[next_state, :]) - Q[state, action])

            # Set the current state to the new state
            state = next_state

    return Q
