Sub Hanoi(n, source, destination, helper)
	If n < 1 Then Exit Sub
	Hanoi n - 1, source, helper, destination
	WScript.Echo "Move disk #" & n & " from " & source & " rod to " & destination & " rod."
	Hanoi n - 1, helper, destination, source
End Sub

Hanoi 4, "left", "middle", "right"
