from time import sleep
from os import system, name
    
from lib.file import *

def header(txt):
  lines = '-' * 30
  print(lines)
  print(txt.center(30))
  print(f'{lines}\n')

def menu(options):
  header('Contact book')

  count = 1
  for option in options:
    print(f'{count} -> {option}')
    count += 1
  
  print(f'{"-" * 30}')
  return int(input('Type your option: '))

def clear():
  if name == 'nt': 
    _ = system('cls')  
  else: 
   _ = system('clear')

file = 'contacts.txt'

if fileExists(file):
  print(f'{file} file already exists, this file will be used to load your contacts')
  input('Press enter to continue...\n')
  clear()
else:
  print(f"{file} file doesn't exists, a file with this name will be created")
  createFile(file)
  input('Press enter to continue...\n')
  clear()

while True:
  option = menu(['List contacts', 'Add contacts', 'Edit contact', 'Remove contact', 'Exit'])
  
  if option == 1:
    clear()
    header('List contacts')
    readFile(file)
    print('-' * 30)
    input('Press enter to continue...\n')
    clear()
  elif option == 2:
    clear()
    header('Add contacts')
    contactName = input('Enter contact name: ')
    contactNumber = input('Enter contact number: ')
    addContact(file, contactName, contactNumber)
    input('Press enter to continue...\n')
    clear()
  elif option == 3:
    clear()
    header('Edit contact')
    readFile(file)
    selected = int(input('Select your contact id: '))

    editContact(file, selected)
    input('Press enter to continue...\n')
    clear()
  elif option == 4:
    clear()
    header('Remove contact')
    readFile(file)
    selected = int(input('Select your contact id: '))

    removeContact(file, selected)
    input('Press enter to continue...\n')
    clear()
  elif option == 5:
    print('Exiting...')
    break
  else:
    print('\033[31mERROR! type a valid option!\033[m')

sleep(2)