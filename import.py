# TODO
import sys 
import csv
import sqlite3  

# this part check for argv elements count 

if len(sys.argv) != 2:     
	exit("Usage: python import.py characters.csv")
print("This works :) ") 

# this line connects python to database 

db = sqlite3.connect('students.db')

# this part insert into database and split name cells to 3 cells 

with open(sys.argv[-1], 'r') as characters:
	reader = csv.DictReader(characters)     
	for row in reader:         
		house = row['house']         
		birth = row['birth']         
		curr_name = row['name'].split()
		if len(curr_name) == 3:
			first, middle, last = curr_name[0], curr_name[1], curr_name[2]  
		else:
			first, middle, last = curr_name[0], None, curr_name[1]   
		db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)", (first, middle, last, house, birth))
		db.commit()            
print("OK")
