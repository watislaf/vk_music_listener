import requests
import vk
import random
import datetime

idd = (random.uniform(0, 20))
# https://oauth.vk.com/authorize?client_id=6607220&display=page&redirect_uri=https://oauth.vk.com/blank.html&scope=friends&response_type=token&v=5.52
try:
    ff = open('id.txt')
    MiId = ff.read(9);
    Begi = 'https://api.vk.com/method/'
    IdAp = 6607220
    Login = '+375447574459'
    password = 'янина67'
    method = 'friends.get?'
    AccessT = 'fa722d14ec150a45e9ba3c13570bdf5aeb0dd99ad2c5b6cd1a6cc214916aa9d5b95917d9c8331d7b73d6e'
except:
    print("ERROR  "+datetime.datetime.now().time()+" строки 6-13 , аутификаторЖ:"+str(idd))

try:
    info = requests.get(Begi + method+'v=5.52&access_token='+AccessT)
except:
    print("ERROR  "+str(datetime.datetime.now().time())+" строки 24 , аутификаторЖ:"+str(idd))
result = info.text
session = vk.Session(access_token=AccessT)
vkapi = vk.API(session, v=5.74)
ss = vkapi.status.get(user_id = MiId)

try:
    f = open('text.txt', 'w', encoding='UTF-8')
except:
    print("ERROR  "+str(datetime.datetime.now().time())+" строки 50, аутификаторЖ:"+str(idd))

try:
    f.write(ss['text'])
except:
    print("ERROR  "+str(datetime.datetime.now().time())+" строки 55, аутификаторЖ:"+str(idd))


