import random
import datetime

print('OTP Generator')

otp_list = [] 

def random_gen(seed):
  time = datetime.datetime.now()
  time = time.microsecond
  # print("Time: ", time)
  # print("Inter: ", time*seed)
  num = int(str(time*seed)[:4])
  # print("Seed: ", seed)
  seed = seed * num * seed
  # print("Num: ", num)
  return num

seed = 1528

for n in range(0,100):
  num = random_gen(seed)  
  print(str(n+1) + ": " + str(num))
  if num in otp_list:
    print("Repetition: ", num, " Position: ", otp_list.index(num)+1)

  otp_list.append(num)

def receiver(rev_num):
  print('\n-----Receiver------')
  print("Received the OTP for Challenge is : ",rev_num)
  temp = rev_num+2
  print("Responding to Sender...")
  return temp
  # receiver(otp_num)

def sender():
  print('\n-----Sender------')
  otp_num = random_gen(seed)
  print("Sending the OTP for Challenge")
  rev = receiver(otp_num)
  print('\n-----Sender------')
  print("Recieved Response from Receiver")
  if rev == (otp_num+2):
    print("Otp Has Been Verified ....")
    print("Authentication Successfull!!!")
    print("Reciver is Authenticated")

def vsender(rev_num):
  print('\n-----Sender------')
  print("Received the OTP for Challenge is : ",rev_num)
  temp = rev_num+2
  print("Responding to Receiver...")
  return temp
  # receiver(otp_num)

def vreceiver():
  print('\n-----Receiver------')
  otp_num = random_gen(seed+1234)
  print("Sending the OTP for Challenge to Sender")
  rev = vsender(otp_num)
  print('\n-----Receiver------')
  print("Recieved Response from Sender")
  if rev == (otp_num+2):
    print("Otp Has Been Verified ....")
    print("Authentication Successfull!!!")
    print("Sender is Authenticated")

print("\n\nTwo Authentication Beigns-----")
sender()
vreceiver()