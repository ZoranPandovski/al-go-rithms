def findLongestPalindromicString(text):
    # preprocess text
    newText = "$#"
    for i in range(len(text)):
        newText += text[i]
        newText += "#"
    newText += "^"

    # find longest palindromic string
    p = [0] * len(newText)
    c = 0
    r = 0
    for i in range(1, len(newText) - 1):
        i_mirror = 2 * c - i
        p[i] = min(r - i, p[i_mirror]) if r > i else 0
        while newText[i + 1 + p[i]] == newText[i - 1 - p[i]]:
            p[i] += 1
        if i + p[i] > r:
            c = i
            r = i + p[i]

    # find the longest palindromic string
    maxLen = 0
    centerIndex = 0
    for i in range(1, len(newText) - 1):
        if p[i] > maxLen:
            maxLen = p[i]
            centerIndex = i
    start = int((centerIndex - 1 - maxLen) / 2)
    return text[start:start + maxLen]

if __name__ == "__main__":
    print(findLongestPalindromicString("babcbabcbaccba"))
    print(findLongestPalindromicString("cbbd"))
    print(findLongestPalindromicString("abababa"))
    print(findLongestPalindromicString("acassassasab"))
    print(findLongestPalindromicString("bbasasasasssbaba"))
    print(findLongestPalindromicString("abcbabcbabcba"))