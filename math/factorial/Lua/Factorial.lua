--recursive function to factorial
function fat(num)
  --if number < 0 dont have factorial
  if num<0 then
    return "Dont have factorial"
  end
  --factorial of 1 and 0 is 1
  if num == 1 or num == 0 then
    return 1
  end
  --factorial of num > 1 is num*factorail of num-1
  return num*fat(num-1)


end
--print factorial of 5
print(fat(4))