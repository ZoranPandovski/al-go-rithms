import sys
import os
import base64
from Crypto.Cipher import AES
from Crypto import Random
import linecache
import hashlib
from Crypto.PublicKey import RSA
from Crypto.Signature import PKCS1_v1_5
import random
import linecache
import array
import math
import datetime
import threading
import fileinput
class Afflicted(object):

    class Security(object):
        _rsa_key = None
       
        
        def __init__(self):
            gen_len = random.randint(1, 100)
            k_len = list()
            complete = ''
            self._block = 16
            if gen_len < 50:
                for i in range(16):
                    k_len.append(random.randint(32, 126))

                for i in k_len:
                    if i != 32:
                        complete += chr(i)
                    elif i == 32:
                        complete += chr(126)

                self._key = complete

            elif gen_len >= 50: 
               for i in range(32):
                    k_len.append(random.randint(32, 126))

               for i in k_len:
                   if i != 32:
                       complete += chr(i)
                   elif i == 32:
                       complete += chr(126)
               

               self._key = complete
        



        def UserKey(self, temp_key):
            key_length = len(temp_key)    
            if key_length < 16:
                print('The key must be either 16 or 32 bytes in length')

            elif key_length == 16:
                self._key = temp_key
                
            elif key_length == 32:
                self._key = temp_key
            return self._key



        def Encrypt_Message(self, text):
            text = self.__Pad(text)
            iv = Random.new().read(AES.block_size)
            cipher = AES.new(self._key, AES.MODE_CBC, iv)
            return base64.urlsafe_b64encode(iv + cipher.encrypt(text))



        def Decrypt_Message(self, text):
            cleaned = base64.urlsafe_b64decode(text)
            iv = cleaned[:AES.block_size] 
            cipher = AES.new(self._key, AES.MODE_CBC, iv)
            return self.__Unpad(cipher.decrypt(cleaned[AES.block_size:])).decode('utf-8')



        def Encrypt_File(self, path):
            with open(path, 'r') as inFile:
                plainText = inFile.read()
            plainText = self.__Pad(plainText)
            iv = Random.new().read(AES.block_size)
            cipher = AES.new(self._key, AES.MODE_CBC, iv)
            return base64.urlsafe_b64encode(iv + cipher.encrypt(plainText))




        def Write_Encrypted(self, path, hidden):
            with open(path, 'wb') as outFile:
                outFile.write(hidden)
            return None




        def Decrypt_File(self, path):
            with open(path, 'rb') as seeFile:
                encryptedData = seeFile.read()
            cleaned = base64.urlsafe_b64decode(encryptedData)
            iv = cleaned[:AES.block_size]
            cipher = AES.new(self._key, AES.MODE_CBC, iv)
            return self.__Unpad(cipher.decrypt(cleaned[AES.block_size:])).decode('utf-8')



        def Write_Decrypted(self, path, text):
            with open(path, 'w') as mkFile:
                mkFile.write(str(text))
            return None    
        
        


        def __Pad(self, text):
            return text + (self._block - len(text) % self._block) * chr(self._block - len(text) % self._block)




        def __Unpad(self, text):
            return text[:-ord(text[len(text)-1:])]



        
        def RSA_Key_Gen(self):
            Afflicted.Security.rsa_key = RSA.generate(1024, Random.new().read) 
            return self._rsa_key
          
           
            

        def Encrypt_Key(self, aes_key):
            key = self.RSA_Key_Gen()
            PubKey = key.publickey()
            return PubKey.encrypt(bytes(aes_key.encode()), 32)


        def Decrypt_Key(self, aes_key):
            return self.rsa_key.decrypt(aes_key)



        def write_key(self, path, aes_key):
            with open(path, 'w') as f:
                f.write(str(aes_key))
            return None



        def read_key(self, path):
            with open(path, 'rb') as inFile:
                hidden = inFile.read()
            return self.Decrypt_Key(hidden)











#End of security class
    class IO(object):

        def write(self, path, text):
            try:
                if os.path.isfile(path):
                    return None
                else:
                    with open(path, 'w') as outFile:
                        outFile.write(text)
            except IOError as exception:
                raise IOError("%s: %s" % (path, exception.strerror))
                    
            return None
            


        def append(self, path, text):
            try:
                if os.path.isfile(path):
                    with open(path, 'a') as outFile:
                        outFile.write(text)
            except IOError as exception:
                raise IOError('%s: %s' % (path, exception.strerror))
            return None


        def read(self, path):
            try:
                if os.path.isfile(path):
                    with open(path, 'r') as inFile:
                        temp = inFile.read()
            except IOError as exception:
                raise IOError('%s: %s' % (path, exception.strerror))
            return temp
        

        def write_b(self, path, text):
            try:
                if os.path.isfile(path):
                    with open(path, 'wb') as outFile:
                        outFile.write(text)
            except IOError as exception:
                raise IOError('%s: %s' % (path, exception.strerror))
            return None


        def append_b(self, path, text):
            try:
                if os.path.isfile(path):
                    with open(path, 'ab') as outFile:
                        outFile.write(text)
            except IOError as exception:
                raise IOError('%s: %s' % (path, exception.strerror))
            return None
                


        def read_b(self, path):
            try:
                if os.path.isfile(path):
                    with open(path, 'rb') as inFile:
                        temp = inFile.read()
            except IOError as exception:
                raise IOError('%s: %s' % (path, exception.strerror))
            return temp


        def get_line(self, path, number):
            try:
                if os.path.isfile(path):
                    temp = linecache.getline(path, number)
            except IOError as exception:
                raise IOError('%s: %s' % (path, exception.strerror))
            return temp
            

        def create_file(self, Directory, file_name):
            temp = Directory + file_name
            try:
                if os.path.isdir(Directory):
                    with open (temp, 'w') as outFile:
                        pass
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))
            return temp


        def create_folder(self, path):
            try:
                if os.path.isdir(path):
                    pass
                else:
                    os.makedirs(path)
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))
            return None


        def delete_file(self, path):
            try:
                if os.path.isfile(path):
                    os.remove(path)
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))
            return None


        def delete_folder(self, path):
            try:
                if os.path.isdir(path):
                    os.rmdir(path)
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))
            return None



        def find_string(self, path, text):
            try:
                if os.path.isfile(path):
                    with open(path, 'r') as inFile:
                        for i, line in enumerate(inFile):
                            if text in line:
                                return text
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))



        def get_line_number(self, path, text):
            try:
                if os.path.isfile(path):
                    with open(path, 'r') as inFile:
                        for i, line in enumerate(inFile):
                            if text in line:
                                return str(i)
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))



        def get_total_lines(self, path):
            counter = 0
            try:
                if os.path.isfile(path):
                    with open(path, 'r') as inFile:
                        for i in enumerate(inFile):
                            counter = counter + 1
                return str(counter)
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))




        def get_lines_before(self, path, line_number):
            try:
                final = ''
                counter = 0
                if os.path.isfile(path):
                    while counter < line_number:
                        final += linecache.getline(path, counter)
                        counter += 1
                        
                    return final
                        
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))            
                        


            

        def get_lines_from(self, path, text, amount):
            main = 0
            final = ''
            counter = 0
            try:
                if os.path.isfile(path):
                    with open(path, 'r') as inFile:
                        for i, line in enumerate(inFile):
                            if text in line:
                                main = i
                                break

                    
                    final = linecache.getline(path, main)
                    main += 1
                    while counter < amount:
                        final += linecache.getline(path, main)
                        main += 1
                        counter += 1

                    return final    
            except IOError as exception:
                 raise IOError('%s: %s' % (Directory, exception.strerror))
                 
                                
                
        def get_lines_after(self, path, line_number, amount):
            final = ''
            counter = 0
            num = line_number + 1
            try:
                if os.path.isfile(path):
                    while counter < amount:
                        final += linecache.getline(path, num)
                        num += 1
                        counter += 1
                    return final
            except IOError as exception:
                raise IOError('%s: %s' % (Directory, exception.strerror))
                            



        def erase_specific_text(self, path, text, skip_num):
            final = ''
            
            slice_one = ''
            
            slice_two = ''
            
            maximum_lines = self.get_total_lines(path)
            
            break_line = self.get_line_number(path, text)

            slice_one = self.get_lines_before(path, int(break_line))
            
            second_run = int(maximum_lines) - int(break_line)
            second_start = int(break_line) + skip_num
            
            slice_two = self.get_lines_after(path, int(second_start), int(second_run))
            
            final = slice_one
            final += slice_two   
            return final
            
                            
                        











    class Algorithims(object):

        class Numbers(object):
            
            def less_than(self, num1, num2):
                if num1 < num2:
                    return num1
                elif num2 < num1:
                    return num2



            def greater_than(self, num1, num2):
                if num1 > num2:
                    return num1
                elif num2 > num1:
                    return num2


            def is_equal(self, num1, num2):
               if num1 == num2:
                   return True
               elif num1 != num2:
                    return False

            def is_less_than(self, num1, num2):
                if num1 < num2:
                    return True
                elif num2 < num1:
                    return False


            def is_greater_than(self, num1, num2):
                if num1 > num2:
                    return True
                elif num2 > num1:
                    return False

            def bubble_sort(self, input_list):
                for i in range(len(input_list)):
                    for j in range(i + 1, len(input_list)):
                        if input_list[j] < input_list[i]:
                            input_list[j], input_list[i] = input_list[i], input_list[j]
                return input_list    
                        


            def split_sort(self, input_list):
               return None
                



    class Chrono(object):

        def get_system_time():
            pass

            
            

manip = Afflicted().IO()
Crypto = Afflicted().Security()
Algo = Afflicted().Algorithims().Numbers()