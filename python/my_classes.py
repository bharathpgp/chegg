# Accessory class
class Accessory:
    # initializes the properties of Accessory class
    def __init__(self, id, name, color, price):
        self.id = id
        self.name = name
        self.price = price
        self.color = color

    # returns the id, name, color and price
    def __str__(self):
        return "Accessory: number: {0} name: {1} color: {2} price: ${3}".format(self.id, self.name, self.color, self.price)
