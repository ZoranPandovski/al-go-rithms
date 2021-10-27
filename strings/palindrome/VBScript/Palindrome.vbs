Function palindrome(word)
	palindrome = true	'Be optimistic
	
	Dim i : For i = 1 to len(word)/2
		c = LCase(Mid(word, i, 1))
		ch = LCase(Mid(word, len(word) - i + 1, 1))
		If c <> ch then
			palindrome = false
			'Exit Function
		End If
	Next

	k = "is" : If not palindrome then k = "is not"
	WScript.Echo """" & word & """ " & k & " a palindrome."
End Function

WScript.echo palindrome("a")
WScript.echo palindrome("bb")
WScript.echo palindrome("eve")
WScript.echo palindrome("noon")
WScript.echo palindrome("room")
WScript.echo palindrome("racecar")
WScript.echo palindrome("defiled")
WScript.echo palindrome("hannah")
