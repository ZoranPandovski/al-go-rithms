def bayes_rule(probA, probB):
    return probA / probB * 100

if __name__ == "__main__":
    probability_A = float(input("Enter the probability of A: "))
    probability_B = float(input("Enter the probability of B: "))
    print(bayes_rule(probability_B, probability_A))
