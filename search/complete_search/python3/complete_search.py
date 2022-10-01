a = [0, 72, 21, 15, 36, 55, 81, 9, 27, 42, 63, 12, 18, 100]
sol = False
subset = []

def complete_search(idx, sum) -> bool:
    global a, sol, subset
    if (idx > len(a)) or (sum > 100):
        return sol
    if sum == 100:
        if not sol:
            sol = True
        print("100 = ")
        for i, item in enumerate(subset):
            print(f"{item}")
            if(i < len(subset) - 1):
                print(" + ")
        print("\n")
        return sol
    try:
        subset.append(a[idx])
        complete_search(idx+1, sum+a[idx])
        subset.pop()
        complete_search(idx+1, sum)
    except IndexError:
        return sol

if __name__ == "__main__":
    
    solution = complete_search(0, 0)
    if not solution:
        print("Can't reach 100")