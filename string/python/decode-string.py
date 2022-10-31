class Solution:
    def decodeString(self, s: str) -> str:
        stack = []
        for letter in s:
            if letter != ']':
                stack.append(letter)
            else:
                encode_str = str()
                while stack[-1] != '[':
                    encode_str += stack.pop()
                stack.pop()
                times = ''
                while stack:
                    try:
                        int(stack[-1])
                        times += stack.pop()
                    except:
                        break
                times = int(times[::-1])
                for i in range(times):
                    stack.extend(encode_str[::-1])
        return ''.join(stack)