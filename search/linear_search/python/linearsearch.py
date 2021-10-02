arr=[10,2,3,4,23,5,21,45,90,100];
item=int(input("Enter the item which you want to search"));
for i in range(0,len(arr)):
  if arr[i]==item:
    flag=i+1;
    break;
  else:
    flag=0;
if falg!=0:
  print("Item found at location %d", flag));
else:
  print("Item not found");
