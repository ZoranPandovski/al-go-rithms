# -*- coding: utf-8 -*-
"""
Created on Tues Oct 12 15:30:00 2021
@author: zedutra
"""

from selenium import webdriver
import time

driver = webdriver.Firefox()
driver.get("https://web.whatsapp.com/")

qrcode = input("Scan QR CODE and press enter")
contact = str(input('Contact name: '))
message = str(input('Spam message: '))
repeat = int(input('How many messages: '))
contact = driver.find_element_by_xpath("//span[@title='{}']".format(contact))
contact.click()

count = 0
while count < repeat:
    time.sleep(2)
    inputMessage = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div[1]/div[4]/div[1]/footer/div[1]/div/div/div[2]/div[1]/div/div[2]')
    inputMessage.click()
    inputMessage.send_keys(message)
    inputSend = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div[1]/div[4]/div[1]/footer/div[1]/div/div/div[2]/div[2]/button')
    inputSend.click()
    count += 1
    
