# -*- coding: utf-8 -*-
"""
Created on Tues Oct 12 15:00:00 2021
@author: zedutra
"""

# Imports
from selenium import webdriver
import time
import os


# Inputs
user = str(input('Insert instagram user: '))


# Starting webdriver
driver = webdriver.Firefox()
driver.get("https://www.instagram.com/" + user)


# Closing popup
driver.implicitly_wait(4)
driver.find_element_by_xpath('//*[@id="react-root"]/section/nav/div[2]/div/div/div[3]/div/div/div/button').click()


# Downloading photos
photos = driver.find_elements_by_class_name("_9AhH0")
if len(photos) > 0:
    os.mkdir(user)
    countphotos = 0
    countscroll = 0
    while countphotos < len(photos):
        photos[countphotos].screenshot('./{}/img{}.png'.format(user, countphotos))
        driver.execute_script("window.scrollTo({}, {});".format(countscroll, countscroll + 100))
        print('Downloading: {}'.format(countphotos))
        countphotos += 1
        countscroll += 100
        time.sleep(1)
    print('{} Downloaded photos'.format(len(photos)))
else:
    print('No photos available')
driver.close()
