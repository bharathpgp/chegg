# import myfucntions
import my_functions

# get the dictionary of accessories
accessorys = my_functions.load_accessories()

# loop through the dictionary to print them out
for id, accessory in accessorys.items():
    print(accessory)
