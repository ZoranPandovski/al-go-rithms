# Python 3 program to sort 
# an array according to given 
# indexes 
  
# Function to reorder 
# elements of arr[] according 
# to index[] 
def reorder(arr,index, n): 
  
    temp = [0] * n; 
  
    # arr[i] should be 
        # present at index[i] index 
    for i in range(0,n): 
        temp[index[i]] = arr[i] 
  
    # Copy temp[] to arr[] 
    for i in range(0,n): 
        arr[i] = temp[i] 
        index[i] = i 
      
# Driver program 
arr = [50, 40, 70, 60, 90] 
index = [3, 0, 4, 1, 2] 
n = len(arr) 
  
reorder(arr, index, n) 
  
print("Reordered array is:") 
for i in range(0,n): 
    print(arr[i],end = " ") 
  
print("\nModified Index array is:") 
for i in range(0,n): 
    print(index[i],end = " ") 
