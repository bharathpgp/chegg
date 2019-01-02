# import Accessory class
from my_classes import Accessory

# takes nothing and returns a dictionary of accessories
def load_accessories():
    accessorys = {}
    acc = Accessory(1, 'Adult Helmet', 'Black', 24.99)
    accessorys[1] = acc
    acc = Accessory(2, 'Child Helmet', 'Black', 19.99)
    accessorys[2] = acc
    acc = Accessory(3, 'Foam Grips', 'Blue', 9.99)
    accessorys[3] = acc
    acc = Accessory(4, 'Child Elbow & Knee Pads', 'Pink', 19.99)
    accessorys[4] = acc
    return accessorys
