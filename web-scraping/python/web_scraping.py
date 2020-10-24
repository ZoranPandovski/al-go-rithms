# -*- coding: utf-8 -*-
"""
Created on Wed Apr 12 14:54:09 2017

@author: venkatraman
"""

# Dependencies
import smtplib
import email.message
from bs4 import BeautifulSoup
import urllib2
import base64
import re
import sys  

try:
    reload(sys)  
    sys.setdefaultencoding('utf8')
except NameError:  # reload() was moved in Python 3
    pass

# Routine to scrape the day's comics from a site and add to HTML mail
def getComics():
    page = urllib2.urlopen("http://comics.azcentral.com/")
    soup = BeautifulSoup(page, "lxml")
    comic = list(soup.findAll('img', {"class":"uclick-display"}))
    comic.append(soup.findAll('img', {"class":"comic-display"})[0])
    comic = comic[-1:] + comic[:-1]
    title = soup.findAll('span', {"class":"comic-name"})
    dt = soup.findAll("span", {"class":"comic-date-r"})
    url1 = list()
    for i in comic:
        url1.append(i['src'])
    urlhtml = ""
    for i in range(len(url1[0:5])):
        urlhtml += """<div style = "background-color:#f2f2f2;padding:2px"><p style = "color:#344f75">%s</p>
                        <span style = "display:inline;float:right;color:#999999">%s</span></div>
                        <img src = '%s',alt = "Your Comics"></img><br><br>""" %(title[i].text, dt[i].text, url1[i])
    return(urlhtml)

# Routine to scrape headlines from a news website 

def getNews():
    page = urllib2.urlopen("https://www.inshorts.com/en/read")
    soup = BeautifulSoup(page, 'lxml')
    news_image = soup.findChildren('div', {"class":"news-card-image"})
    news_title = soup.findAll('div', {'class':'news-card-title news-right-box'})
    news_read_more = soup.findAll("div", {"class":"read-more"})
    news_body = soup.findAll("div", {"itemprop":"articleBody"})
    news_readmore = []
    news_img = []
    news_tit = []
    news_con = []
    for x in range(len(news_image)):
        news_img.append(re.findall("url\((.*)\)", news_image[x]['style'])[0])
        news_tit.append(re.split("\\n\n", news_title[x].text)[1])
        news_con.append(news_body[x].text)
        news_readmore.append(news_read_more[x].findChildren())
        
    news_readmore = news_readmore[0:3]
    news_img = news_img[0:3]
    news_tit = news_tit[0:3]
    news_con = news_con[0:3]
    newshtml = ""
    for i in range(3):
        newshtml += """<div style="background-color:#FFFFFF;color:#000000;padding:15px">
                        <img src = %s, align = "left", width = "171", height = "128", style = "padding:15px"></img></div>
                        <div style = "display:inline"><h4>%s</h4>
                        <p style = "font-size:12px;padding-left:15px">%s</p>
                        <p style = "font-size:8px;color:#A9A9A9;padding-left:15px">read more at%s</p></div><br>""" %(news_img[i],news_tit[i], news_con[i], news_readmore[i])
    
    return(newshtml)

# Routine to write a HTML mail

me = "mailfrom@someone.com"
you = ["mailto@someonelse.com"]  # additional recipients can be added as an array 
password = base64.b64decode(b"TVlwYXNzd29yZA==")

# Create message container - the correct MIME type is multipart/alternative.
html = """\
<html>
  <head></head>
  <body>
  <h3>Hi!<br></h3>
  <div style="border-style:dotted solid double none">
       <div style="background-color:#000000;color:#FFFFFF;border-left:groove;">
       <h4>Here is your digest</h4></div>
       %s
       </div><br><hr></div><div style="border-style:dotted solid double none">
       <div style="background-color:#000000;color:#FFFFFF;border-left:groove;">
       <h4>Here is your comic</h4></div>
       %s
  </body>
</html>
""" %(getNews(), getComics())

# Send mail routine for gmail

msg = email.message.Message()
msg['Subject'] = 'Daily Digest'
msg['From'] = me
msg['To'] = ','.join(you)
msg.add_header('Content-Type','text/html')
msg.set_payload(html)

mail = smtplib.SMTP('smtp.gmail.com', 587)

mail.ehlo()

mail.starttls()

mail.login(me, password)
mail.sendmail(me, you, msg.as_string())
mail.quit()
