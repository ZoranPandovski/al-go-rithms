'''
Boyer–Moore string-search algorithm is an efficient string-searching algorithm
that is the standard benchmark for practical string-search literature.The
algorithm preprocesses the string being searched for (the pattern), but not
the string being searched in (the text).The Boyer-Moore algorithm uses
information gathered during the preprocess step to skip sections of the text, 
resulting in a lower constant factor than many other string search algorithms.
The key features of the algorithm are to match on the tail of the pattern
rather than the head, and to skip along the text in jumps of multiple
 characters rather than searching every single character in the text.
'''
def boyer_moore(text,pattern):
    n = len(text)                         # lenght of text
    m = len(pattern)                      # length of pattern
    if m == 0:
        return None
    last = {}                             # build 'last' dictionary
    for k in range(m):
        last[pattern[k]] = max(1,m-k-1)   # bad match table
    t = m-1                               # an index into text
    p = m-1                               # an index into pattern
    while t < n:
        if text[t] == pattern[p]:
            if p == 0:
                return t
            else:
                t -= 1
                p -= 1
        else:
            j = last.get(text[t],-1)
            t += m-min(p,j+1)
            p = m-1
    return None
