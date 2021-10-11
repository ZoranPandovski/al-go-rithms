Function factorial(n)
	if n < 2 then factorial = n : Exit Function
	factorial = n * factorial(n - 1)
End Function

n = 1 : WScript.Echo "The factorial of " & n & " is " & factorial(n)
n = 2 : WScript.Echo "The factorial of " & n & " is " & factorial(n)
n = 3 : WScript.Echo "The factorial of " & n & " is " & factorial(n)
n = 4 : WScript.Echo "The factorial of " & n & " is " & factorial(n)
