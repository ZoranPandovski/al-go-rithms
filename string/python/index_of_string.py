lass ImplementStrStr:
    def strStr(haystack: str, needle: str) -> int:
        # Base conditions
        if haystack is None or needle is None:
            return -1
        # Special case
        if haystack == needle:
            return 0
        # Length of the needle
        needleLength = len(needle)
        # Loop through the haystack and slide the window
        for i in range(len(haystack) - needleLength + 1):
            if haystack[i:i + needleLength] == needle:
                return i
        return -1
