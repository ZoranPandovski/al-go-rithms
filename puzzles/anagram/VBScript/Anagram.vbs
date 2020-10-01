Function anagram(a, b)
	anagram = true	'Be optimistic

	'We could do a length comparison, but then we wouldn't be able to show a disparity.
	'Also, this gives the flexibility to compare sentences (which might not have the same word count).
	Const ignore = " ,.'?!"

	'We could sort the characters but then it'd be a bit more code to show any disparities.
	'We could use a sparse array (or two) but a collection is more elegant.
	Dim d : Set d = CreateObject("Scripting.Dictionary")

	Dim i : For i = 1 to len(a)
		c = LCase(Mid(a, i, 1))
		If d.Exists(c) then
			d.Item(c) = d.Item(c) + 1
		Else
			d.Add c, 1
		End If
	Next
	For i = 1 to len(b)
		c = LCase(Mid(b, i, 1))
		If d.Exists(c) then
			d.Item(c) = d.Item(c) - 1
		Else
			d.Add c, -1
		End If
	Next

	Dim k : k = d.Keys
	For i = 0 to d.Count - 1
		If Instr(ignore, k(i)) = 0 then
			If d.Item(k(i)) > 0 then
				WScript.Echo a & " has " & d.Item(k(i)) & " more of """ & k(i) & """ than " & b
				anagram = false
			End If
			If d.Item(k(i)) < 0 then
				WScript.Echo a & " has " & 0 - d.Item(k(i)) & " fewer of """ & k(i) & """ than " & b
				anagram = false
			End If
		End If
	Next
	
	k = "is" : If not anagram then k = "is not"
	WScript.Echo """" & a & """ " & k & " an anagram of """ & b & """"
End Function

WScript.echo anagram("new door", "one word")
WScript.echo anagram("maggi", "imagg")
WScript.echo anagram("fuzzy", "wuzzy")
WScript.echo anagram("conversation", "voices rant on")
WScript.echo anagram("New York Times", "monkeys write")
WScript.echo anagram("Tom Marvolo Riddle", "I am Lord Voldemort")
