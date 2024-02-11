# TODO
from sys import argv
import sqlite3

if len(argv) != 2:     
	exit("Usage: python roster.py Housename") 

# print ('this works')  

print('this works')

# db = SQL("sqlite:///students.db") 

db = sqlite3.connect("students.db")  
rows = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last, first", (str(argv[1]),))    
for rows in rows:
	if rows[1] == None:
		print(rows[0] + ' ' + rows[2] + ', born ' + str(rows[3]))
	else:
		print(rows[0] + ' ' + rows[1] + ' ' + rows[2] + ', born ' + str(rows[3]))
		

# Lavender Brown, born 1979 
# Colin Creevey, born 1981 
# Seamus Finnigan, born 1979 
# Hermione Jean Granger, born 1979 
# Neville Longbottom, born 1980 
# Parvati Patil, born 1979 
# Harry James Potter, born 1980 
# Dean Thomas, born 1980 # Romilda Vane, born 1981 
# Ginevra Molly Weasley, born 1981 
# Ronald Bilius Weasley, born 1980 
 