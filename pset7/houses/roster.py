from sys import argv
from cs50 import SQL


# Checks if no file given
if len(argv) != 2:
    print("Usage: python roster.py housename")
    exit(1)
 
 # Initializes db   
housename = argv[1]
db = SQL("sqlite:///students.db")

# Collect all info in form of dicts
student = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", housename)

# Runs through each dict in student
for row in student:
    
    # Prints first name
    print(f"{row['first']}", end=" ")
    
    # Prints middle name if any 
    if row['middle'] != None:
        print(f"{row['middle']}", end=" ")
        
    # Print last name and birth year
    print(f"{row['last']}, born {row['birth']}")
