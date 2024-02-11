import csv  

#will cointain the fields and rows of the pokemon.csv
fields = []
data = []
#try to open the pokemon.csv file on read status
try:
    with open("pokemon.csv", mode ='r') as file:
        pokedex = csv.reader(file)
#assign the first row to fields[]
        fields = next(pokedex)
#assign the remaining row to data[] by iterating through the csv using for loop
        for row in pokedex:
            data.append(row)
#close the pokemon.csv
    file.close()
except:
    print("Error: Something is wrong with \"pokemon.csv\"")
#exit the program if the pokemon.csv is not detected    
    exit()

def search():
    print("")
#user input for the pokemon name
    pokemon = input("Name of the Pokemon: ")
    print("")
#if the pokemon do not exist after the for loop below, the value of pokemon_dont_exist will stay True
    pokemon_dont_exist = True
    for row in data:
#checking if the pokemon name is equal to the value of name contained in the row
        if row[1].lower() == pokemon.lower():
#if the if statement results to true, the pokemon_dont_exist value will be false            
            pokemon_dont_exist = False
#output part of the search            
            print("Name: " + row[1].upper())
            print("Type 1: " + row[2])
            print("Type 2: " + row[3])
            print("Combat Power: " + row[4])
            print("HP: " + row[5])
            print("Attack: " + row[6])
            print("Defense: " + row[7])
            print("Sp. Atk: " + row[8])
            print("Sp. Def: " + row[9])
            print("Speed: " + row[10])
            print("Generation: " + row[11])
            print("Legendary: " + row[12])
#exit the for loop after the if statement is executed            
            break
#display an error message if the pokemon do not exist        
    if pokemon_dont_exist:
        print("Error: The pokemon \""  + pokemon.lower() + "\" don't exist!")

def battle():
    print("")   
    pokemon_1_power = 0;
    pokemon_2_power = 0;
    #user input of the pokemon names
    pokemon_1 = input("Name of first pokemon: ")
    pokemon_2 = input("Name of second pokemon: ")
    winner = ""
    print("")
    #looping through the rows of data and if the pokemon names are in the csv, the pokemon powers will have value according to the pokemon name
    for row in data:
        if row[1].lower() == pokemon_1.lower():
            pokemon_1_power = int(row[4])
        if row[1].lower() == pokemon_2.lower():
            pokemon_2_power = int(row[4])
#if the pokemon powers are 0, the user input pokemon names are not in the csv
    if pokemon_1_power == 0:
        print("Error: The pokemon \""  + pokemon_1 + "\" don't exist!")
    if pokemon_2_power == 0:
        print("Error: The pokemon \""  + pokemon_2 + "\" don't exist!")
#compute for the winner        
    if pokemon_1_power > 1 and pokemon_2_power > 1:
        if pokemon_1_power > pokemon_2_power:
            winner = pokemon_1.lower()
        elif pokemon_1_power < pokemon_2_power:
            winner = pokemon_2.lower()
        else:
            winner = "It's a tie!!!"
#the output part for the battle
        print("Battle Details:")
        print(pokemon_1 + "'s Combat power: " + str(pokemon_1_power))
        print(pokemon_2 + "'s Combat power: " + str(pokemon_2_power))
        print("")
        print("Battle between " + pokemon_1 + " and " + pokemon_2 + " commencing.....")
        print("The winner of the battle is: " + winner)

def export():
    print("")
    type_dont_exist = True
#user input for the type    
    type = input("Please enter a pokemon type: ")
#verify if the user input type is in the csv    
    for row in data:
        if row[2].lower() == type.lower() or row[3].lower() == type.lower():
            type_dont_exist = False
            break
    if type_dont_exist:
        print("Error: Pokemon type don't exist!")
    else:
# try catch for making the type.csv
        try:
            with open("types.csv", 'w', newline='') as file:
                writer = csv.writer(file)
#write the fields to the type.csv                
                writer.writerow(fields)
#loop through the pokemon data, if type 1 of the pokemon is equal to the user input type, write the row in the file                
                for row in data:
                    if row[2].lower() == type.lower():
                        writer.writerow((row))
#close the types.csv                        
                file.close()
            print("Please check the \"types.csv\" file for the output")
#error handler (if the types.csv is open while generating another csv, an error will occur)            
        except:
            print("Error: Close the file \"types.csv\" first!")

#The starting interface
choice = 0
print("-----Pokedex-------")
print("(1) Search for a pokemon")
print("(2) Battle Simulator")
print("(3) Export a csv based on type")
print("")

while choice != '1' and choice != '2' and choice != '3':
    choice = input("Please enter your choice trainer!: ")
if choice == '1':
    search()
elif choice == '2':
    battle()
elif choice == '3':
    export()
input()