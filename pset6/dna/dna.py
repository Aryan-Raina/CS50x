import sys
import csv


# Opening files and initializing a list to store the STRs to be tested
dna = open(sys.argv[2], "r").read()
dataRead = csv.reader(open(sys.argv[1]))
dataDict = csv.DictReader(open(sys.argv[1]))
STRs = []

# A dict with key = STR and value = max repeates of that STR in DNA
repeat = {}

# Adding the STRs to be checked in STRs list
for rows in dataRead:
    for i in range(1, len(rows)):
        STRs.append(rows[i])
    break   
    
# Fills the repeat dict with how many of the s STR is in the DNA consequenty
for seq in STRs:
    maxim = 0
    for i in range(len(dna)):
        counter = 0
        j = i
        while(dna[j: j + len(seq)] == seq):
            counter += 1
            j += len(seq)
        if counter > maxim:
            maxim = counter
    repeat[seq] = maxim

# No of matches declared as 0
matches = 0

# Finds matches
for rows in dataDict:
    match = True
    for seq in STRs:
        if int(rows[seq]) != repeat[seq]:
            match = False
    if match:
        print(rows['name'])
        matches += 1

# If no match        
if matches == 0:
    print("No Match")
