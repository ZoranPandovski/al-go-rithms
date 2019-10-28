this is the converting denary to roman number program in visual basic
basically how it works is adding a roman number each time the program subtract the corresponding denary number from the number user inputed 
using a decessing order  

Sub Main()
        Dim a As New List(Of Integer)(New Integer() {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1})
        Dim roman As New List(Of String)(New String() {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"})
        Dim num, i As Integer
        Dim rnum As String
        rnum = ""
        num = Console.ReadLine()
        For i = 0 To 12
            While num >= a(i)
                num = num - a(i)
                rnum = rnum & roman(i)
            End While
        Next
        Console.WriteLine(rnum)
        Console.ReadKey()
    End Sub
