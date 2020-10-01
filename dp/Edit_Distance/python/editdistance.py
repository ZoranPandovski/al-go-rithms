'''
The First line of the input contains an integer T denoting the number of test cases. Then T test cases follow. Each tese case consists of two lines. The first line of each test case consists of two space separated integers P and Q denoting the length of the strings str1 and str2 respectively. The second line of each test case coantains two space separated strings str1 and str2 in order.

Output:
Corresponding to each test case, pirnt in a new line, the minimum number of operations required.

Constraints:
1 <= T <= 50
1 <= P <= 100
1 <= Q <= 100

Example:
Input:
1
4 5
geek gesek

Output:
1

Explanation:
Testcase 1: One operation is required to make 2 strings same i.e. removing 's' from str2.

'''
T=int(input())

for cases in range(T):
    
    m,n=map(int,input().split())
    s1,s2=map(str,input().split())
    
    dp=[[0 for i in range(m+1)] for j in range(n+1)]
    
    for i in range(1,n+1):
        dp[i][0]=i
    for j in range(1,m+1):
        dp[0][j]=j
    
    for i in range(1,m+1):
        for j in range(1,n+1):
            if s1[i-1]==s2[j-1]:
                dp[j][i]=dp[j-1][i-1]
            else:
                dp[j][i]=min(dp[j-1][i-1]+1,dp[j-1][i]+1,dp[j][i-1]+1)
    print(dp[-1][-1])
    