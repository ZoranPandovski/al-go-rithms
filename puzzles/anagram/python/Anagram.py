def isAnagram(string1, string2):
    
    if(len(string1)==len(string2)):
        listString1 = list(string1.lower())
        listString2 = list(string2.lower())
        
        listString1.sort()
        listString2.sort()
        
        return(listString1 == listString2)
        
    else:
        return False
        
