'https://en.wikipedia.org/wiki/Primality_test#Pseudocode
Function isPrime(n)
	if n <= 3 then
		isPrime = n > 1
	elseif n Mod 2 = 0 or n Mod 3 = 0 then
		isPrime = False
	else
		Dim i : i = 5
		while i * i <= n
			if (n Mod i) = 0 or (n Mod (i + 2)) = 0 then
				isPrime = False : Exit Function
			end if
			i = i + 6
		wend
		isPrime = true
	end if
End Function

Dim n : for n = 1 to 50
	WScript.Echo n & " is Prime: " & isPrime(n)
next
