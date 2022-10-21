import matplotlib.pyplot as plt
# Python program to implement Runge Kutta method


def dydx(x, y):
    return (18 * x + 1.33 * y) / (1.33 * x + 18 * y)
# Finds value of y for a given x using step size h
# and initial value y0 at x0.

def rungeKutta(x0, y0, x, h, Q1=0.5, Q2=0.5, w1=0.5, w2=0.5, c1=1, c2=2, c3=2, c4=1):
    # Count number of iterations using step size or step height h
    yn = []
    n = (int)((x - x0) / h)
    # Iterate for number of iterations.
    y = y0
    for i in range(1, n + 1):
        "Apply Runge Kutta Formulas to find next value of y"
        k1 = h * dydx(x0, y)
        k2 = h * dydx(x0 + Q1 * h, y + w1 * k1)
        k3 = h * dydx(x0 + Q2 * h, y + w2 * k2)
        k4 = h * dydx(x0 + h, y + k3)
        # Update next value of y
        y = y + (1.0 / (c1 + c2 + c3 + c4)) * \
            (c1 * k1 + c2 * k2 + c3 * k3 + c4 * k4)
        yn.append(y)
        # Update next value of x
        x0 = x0 + h
    # print("value of yn ",yn[-1])
    return yn


def rootMeanSquareError(standard,predicted):
    sum = 0
    for a, p in zip(standard, predicted):
        err = (p-a) ** 2
        sum += err
    mean = sum/len(standard)
    rmse = mean**(1/2)
    return rmse


# Driver method
x0 = 0
y = 18 / 1.33
x = 18
h = 0.5

# reducing errors by using modifying values of w,q,ci


def compare():
    errList = []
    y_standard = rungeKutta(x0, y, x, h)
    for i in range(1, 11):
        y_modified = rungeKutta(x0, y, x, h, 0.8, 0.5, 0.8, 0.4, 2, 3, 4, 0)
        err = rootMeanSquareError(y_modified, y_standard)
        errList.append(err)
    print(errList)
    print("minimum error", min(errList), errList.index(min(errList))+1)
    return errList


n = [h,h/2,h/4,h/8,h/16]


def calc():
    List = []
    for i in (n):
        a = rungeKutta(x0, y, x, i)
        b = rungeKutta(x0, y, x, i, 0.8, 0.5, 0.8, 0.4, 2, 3, 4, 0)
        c = rootMeanSquareError(b, a)
        print("A ",a[-1]," b  ",b[-1]," c   ",c )
        List.append(c)
    print("error", c)
    print("error list", List)
    return List



# u = compare()
# print("compare", u)
y = calc()

# plotting the points
plt.plot(n, y)
plt.xlabel('Interval step size (h)')
plt.ylabel('Root mean square error')
plt.title('Error Analysis Graph!')
plt.show()
