# Creating a bubble sort function  
def bubble_sort(list1):  
    # Outer loop for traverse the entire list  
    for i in range(0,len(list1)-1):  
        for j in range(len(list1)-1):  
            if(list1[j]>list1[j+1]):  
                temp = list1[j]  
                list1[j] = list1[j+1]  
                list1[j+1] = temp  
    return list1  
  
list1 = []
num=int(input("enter the number of elements in the array : "))
for i in range(0,num):
    user_input = int(input("Enter a number: "))
    list1.append(user_input)


print("The leader of the array",list1[-1])    