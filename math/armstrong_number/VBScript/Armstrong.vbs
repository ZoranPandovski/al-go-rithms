Function isArmstrong(n)
	if TypeName(n) <> "String" then n = "" & n & ""
	if len(n) < 1 or Left(n, 1) < "0" or Left(n, 1) > "9" then Exit Function

	isArmstrong = False
	Dim sum : sum = 0
	Dim l : for l = 1 to Len(n)
		sum = sum + CLng(Mid(n, l, 1))^Len(n)
	next
	if sum = CLng(n) then isArmstrong = True
End Function

Dim n
n = 1634 : WScript.Echo n & " is Armstrong: " & isArmstrong(n)
