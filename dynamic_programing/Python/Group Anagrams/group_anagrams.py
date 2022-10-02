# Group Anagrams into a list
def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        op = {}
        result = []
        for st in strs:
            key = ''.join(sorted(st))

            if key in op.keys():
                op[key].append(st)

            else:
                op[key] = []
                op[key].append(st)

        for key,value in op.items():
            result.append(value)

        return(result)
