from csv import DictReader, reader
from sys import argv

#check length
if len(argv) < 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit()

#read the dna arrangement from the record
with open(argv[2]) as DNAfile:
    DNAreader = reader(DNAfile)
    for row in DNAreader:
        DNAlist = row#store in string
DNA = DNAlist[0]#create a dictionary
sequences = {}

with open(argv[1]) as peoplefile:
    people = reader(peoplefile)
    for row in people:
        DNASequences = row
        DNASequences.pop(0)
        break

for item in DNASequences: sequences[item] = 1

# assuming redundancies of the qualities from dictionary reference are found, count
for key in sequences:
    l = len(key)
    tempMax = 0
    temp = 0
    for i in range(len(DNA)):
    # after having counted a sequence
        # skip toward the finish of it to try not to count once more
        while temp > 0:
            temp -= 1
            continue# if the segment of dna corresponds to the key && 
        #there is a redundancy of it
        #increase counter
        if DNA[i: i + l] == key:
            while DNA[i - l: i] == DNA[i: i + l]:
                temp += 1
                i += l# compare the value to the previous longest sequence && 
            # if it is longer it becomes the new max
            if temp > tempMax:
                tempMax = temp# store the longest groupings in the dictionary utilizing the correspondent key
    sequences[key] += tempMax

with open(argv[1], newline='') as peoplefile:
    people = DictReader(peoplefile)
    for person in people:
        match = 0
        # analyzes the successions to each individual and prints name
        # leave the program in the event that there is a match
        for DNA in sequences:
            if sequences[DNA] == int(person[DNA]):
                match += 1
        if match == len(sequences):
            print(person['name'])
            exit()
     #otherwise, no match
    print("No match")