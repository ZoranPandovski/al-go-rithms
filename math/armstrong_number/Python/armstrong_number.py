num = input("Enter the number: ")
num_str = str(num)
digit = len(num_str)
answer = 0
for i in range(digit):
        answer += int(num_str[i]) ** digit
if num == answer:
        print("%d is an armstrong number" %num)
else:
        print("%d is not an armstrong number" %num)
