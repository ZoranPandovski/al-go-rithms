#!/usr/bin/env python
# -*- coding: utf-8 -*-
import collections

class DoubleArray:
    def __init__(self, words):
        self.END = 'END'
        self.BASE, self.CHECK, self.CODE = self._build(words)

    def _init_BASE_(self, words):
        return [0 for n in range(len(words)*6)]

    def _init_CHECK_(self, words):
        return [-1 for n in range(len(words)*6)]

    def _build(self, words):
        base = []
        check = []
        code = {}
        count = 1

        # Count Words
        for word in words:
            for ch in word:
                if ch not in code:
                    print(ch) #Check
                    code[ch] = count
                    count += 1
        code[self.END] = count

        encode_word  = []
        encode_words = []
        for word in words:
            for ch in word:
                print(code[ch])
                encode_word.append(code[ch])
            encode_word.append(code[self.END])
            print('encode_word: ',encode_word)
            encode_words.append(encode_word)
            print('encode_words: ',encode_words)
            encode_word = []
        
        # Initialize BASE & CHECK
        base = self._init_BASE_(words)
        check = self._init_CHECK_(words)
        
        queue = collections.deque([(0, 0, len(words), 0)])
        while len(queue) > 0:
            print('Length of queue: ', len(queue))
            print('Queue: ', queue)
            index, left, right, depth = queue.popleft()
            print('index: ', index)
            print('left: ', left)
            print('right: ', right)
            print('depth: ', depth)
            print('encode_words[left]: ',encode_words[left])
            if depth >= len(encode_words[left]):
                left += 1
                if left >= right: continue
            
            count = 0
            result = []
            ch = encode_words[left][depth]
            for i in range(left, right):
                count += 1
                if encode_words[i][depth] != ch:
                    result.append((left+count-1, ch))
                    ch = encode_words[i][depth]
                else:
                    continue
            result.append((left+count, ch))
            
            base_index = index
            check_index = 0
            depth += 1
            Flag = True
            i = 0
            true_left = left
            result_queue = []
            while(Flag):
                for right, ch in result:
                    check_index = base[base_index] + ch + i
                    if check[check_index] == -1:
                        result_queue.append((check_index, left, right, depth, ch))
                        left = right
                    else:
                        result_queue = []
                        left = true_left
                        i += 1
                        break
                else:
                    base[base_index] += i
                    for check_index, left, right, depth, ch in result_queue:
                        check[check_index] = base_index
                        if ch == code[self.END]:
                            base[check_index] = -1
                        queue.append((check_index, left, right, depth))
                    Flag = False

        return base, check, code
                    
    def common_prefix_search(self, word):
        prefix = ""
        prefix_list = []
        for ch in word:
            prefix += ch
            if self.search(prefix):
                prefix_list.append(prefix)
        return prefix_list

    def search(self, word):
        base_index = 0
        check_index = 0
        encode_num = []
        for ch in word:
            try:
                encode_num.append(self.CODE[ch])
            except:
                return None
        encode_num.append(self.CODE[self.END])
        for ch in encode_num:
            check_index = self.BASE[base_index] + int(ch)
            if base_index != self.CHECK[check_index]:
                return None
            base_index = check_index
        if self.BASE[base_index] == -1:
            return True

if __name__ == "__main__":
    words = ["c", "ca", "cat", "cats", "center", "cut", "cute", "do", "dog", "fox",  "rat", "rust", "rus"]
    DA = DoubleArray(words)
    for key, value in sorted(DA.CODE.items(), key=lambda x:x[1]):
        print(key, value)
    print('--------------------------------')
    '''
    for i in range(len(DA.BASE)):
        print(i, DA.BASE[i], DA.CHECK[i])
    '''
    print('--------------------------------')
    print(DA.search("cat"))
    print(DA.search("cut"))
    print(DA.common_prefix_search("rust"))
