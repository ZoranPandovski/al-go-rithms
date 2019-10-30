this is the finding lcm program in visual basic
subtracting method is used in this program to find the lcm
the logic is as follows:
we have 2 number , a&b
1. if a>b , a= a-b
2. if b>a , b=b-a
3. if a!=b , return to step 1 or 2 
4. when they equals , the number is the lcm



Sub Main()
        Dim num1, num2, lcm As Integer
        num1 = Console.ReadLine()
        num2 = Console.ReadLine()
        'calcuate lcm using the subtracting method
        While num1 <> num2
            If num2 > num1 Then
                num2 = num2 - num1
            End If
            If num1 > num2 Then
                num1 = num1 - num2
            End If
        End While
        ' lcm can be num1 or num2 as they both represent the lcm after the calcuation 
        lcm = num1
        Console.WriteLine(lcm)
        Console.ReadKey()
    End Sub
