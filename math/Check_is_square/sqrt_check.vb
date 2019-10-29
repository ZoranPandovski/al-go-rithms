this is the program to check square in visual basic
    
    
    
    Sub Main()
        Dim num As Integer

        num = Console.ReadLine()
        If Math.Sqrt(num) Mod 1 = 0 Then
            Console.WriteLine("it is a square ")
        Else
            Console.WriteLine("not a square ")
        End If
        Console.WriteLine()
        Console.ReadKey()
    End Sub
