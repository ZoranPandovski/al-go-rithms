"""
Compress a string in the following format : AAAABBBCCCCC to A4B3C5
"""

def compress(s):
    
    fin_str = ''
    cha = ''
    length = len(s)
    
    i=0
    
    while i < length:
        
        cha = s[i]
        cnt = 0
        while i < length and s[i] == cha:
            i+=1
            cnt+=1
        
        
        fin_str+= cha + str(cnt)
        
    return fin_str

if __name__ == '__main__':
    check_inp = input("Enter string to compress it:")
    comp_str = compress(check_inp)
    if check_inp == 'AAAABBBCCCCC':
        assert comp_str == 'A4B5C3'
        