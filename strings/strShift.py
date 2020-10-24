def shift_possible(str1,str2):
    if len(str1)==len(str2):
        return str1 and str2 and str2 in str1 * 2
    else:
        print("error")



assert shift_possible("abcde", "cdeab")
#Given two strings A and B, return whether or not A can be shifted some number of times to get B.

#For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
