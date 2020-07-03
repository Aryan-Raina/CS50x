from cs50 import SQL
from sys import argv
import csv


# Checks For Filename in user input
if len(argv) != 2:
    print("Usage : python import.py filename.csv")
    exit(1)

# Opens the csv and start a SQL Query
db = SQL("sqlite:///students.db")
file = csv.DictReader(open(argv[1]))

# Does work for Each Row in csv
for row in file:
    # Splits name in row in first middle and last
    name = (row['name']).split(" ")
    if len(name) == 3:
        first = name[0]
        middle = name[1]
        last = name[2]
    elif len(name) == 2:
        first = name[0]
        middle = None
        last = name[1]
    
    # Gives values to houses, birth from csv directly    
    house = row['house']
    birth = row['birth']
    
    # adds the values obtained in the loop to the students table in db
    db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?);",
               first, middle, last, house, int(birth))
