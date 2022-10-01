Function CreateSquare(size)
	'Creates an N x N magic square
	'In a magic square, every row, column, and diagonal add up to the same number.

	CreateSquare = true	'Be optimistic
	if 0 = (size mod 2) then CreateSquare = false : Exit Function

	'Create array and initialize to zeroes
	Dim square() : Redim square(size,size)
	Dim i, j : for i = 1 to size : for j = 1 to size : square(i,j) = 0 : next : next
	
	'Commence storage
	Dim n : n = 1 : i = 0 : j = int(size/2)
	Do
		square(i + 1, j + 1) = n
		n = n + 1
		Dim newi : newi = (i - 1 + size) mod size
		Dim newj : newj = (j + 1) mod size
		If square(newi + 1, newj + 1) > 0  Then
			i = i + 1
		Else
			i = newi
			j = newj
		End If
	Loop While (n < 1 + size * size)

	Dim magicnumber : magicnumber = size * (size * size + 1) / 2
	
	'Test rows and columns
	For i = 1 to size
		Dim r, c : r = 0 : c = 0
		For j = 1 to size
			r = r + square(i, j) : c = c + square(j, i)
		Next
		If r <> magicnumber Then WScript.Echo "Row sum of " & r & ", should be " & magicnumber : CreateSquare = false
		If c <> magicnumber Then WScript.Echo "Column sum of " & c & ", should be " & magicnumber : CreateSquare = false
	Next
	
	'Test diagonals
	r = 0 : c = 0
	For i = 1 to size
		r = r + square(i, i)
		c = c + square(i, size + 1 - i)
	Next
	If r <> magicnumber Then WScript.Echo "Diagonal sum of " & r & ", should be " & magicnumber : CreateSquare = false
	If c <> magicnumber Then WScript.Echo "Diagonal sum of " & c & ", should be " & magicnumber : CreateSquare = false
	
	'Display it
	For i = 1 to size
		n = ""
		For j = 1 to size
			n = n & square(i, j) & vbTab
		Next
		WScript.Echo n
	Next
	WScript.Echo ""
	
End Function

Sub assert(b)
	'If b = false Then WScript.StdErr.WriteLine "Assertion failed." : Exit
End Sub

assert(CreateSquare(1) = true)
assert(CreateSquare(3) = true)
assert(CreateSquare(5) = true)
assert(CreateSquare(7) = true)
assert(CreateSquare(4) = false)
assert(CreateSquare(6) = false)
