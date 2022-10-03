# 20. Valid Parentheses - LeetCode

# Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

# An input string is valid if:

# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Every close bracket has a corresponding open bracket of the same type.
 

# Example 1:

# Input: s = "()"
# Output: true
# Example 2:

# Input: s = "()[]{}"
# Output: true
# Example 3:

# Input: s = "(]"
# Output: false
 

# Constraints:

# 1 <= s.length <= 104
# s consists of parentheses only '()[]{}'.

class Solution:
    def isValid(self, s: str) -> bool:
#         Here we use a list/stack to store the opening brackets. 
        
#         when we encounter an opening bracket, we store it in the temp list
        
#         When we encounter a closing bracket, we check if the last encountered opening bracket is a match. 
        
#         If there is a match, we pop the matching bracket out and move on.
#         If there is no match, we return False
    
#         After the loop we check if the stack is empty or not
        
#         If stack is not empty, we return False as there are unmatched brakcets present.
    
#         If all goes good, we return True

        temp = [-1]
        for i in s:
            if i == '(' or i == '{' or i == '[':
                temp.append(i)
            elif i == ')' and temp[-1] != '(':
                return False
            elif i == '}' and temp[-1] != '{':
                return False
            elif i == ']' and temp[-1] != '[':
                return False
            else:
                temp.pop(-1)
        if temp == [-1]:
            return True
        else:
            return False