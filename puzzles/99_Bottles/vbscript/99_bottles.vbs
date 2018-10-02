Function bottles(n)
    bottles = n & " bottle" : if n > 1 then bottles = bottles & "s"
End Function

WScript.Echo bottles(99) & " of beer on the wall, " & bottles(99) & " of beer."
for i = 98 to 1 step -1
    WScript.Echo "Take one down and pass it around, " & bottles(i) & " of beer on the wall."
    WScript.Echo bottles(i) & " of beer on the wall, " & bottles(i) & " of beer."
next
WScript.Echo "Take one down and pass it around, no more bottles of beer on the wall." _
    & vbCRLF & "No more bottles of beer on the wall, no more bottles of beer." _
    & vbCRLF & "Go to the store and buy some more, 99 bottles of beer on the wall."
