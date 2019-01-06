class CostException (Exception):
    def __init__(self, msg, cost):
        super().__init__(msg)
        self.cost = cost

# MSRP = Manufactured Sale Price


class ShoppingItem():
    def __init__(self, name, msrp):
        if not isinstance(name, str):
            print("No string")
            raise Exception("The name of the product must be a string")
        if len(name) == 0:
            raise Exception("The name cannot be empty")
        if msrp < 0:
            raise CostException("Cannot be negative", msrp)

        self.__name = name
        self.__msrp = msrp
        self.__currentPrice = msrp

    def setSalesPrice(self, price):
        if price < 0:
            raise CostException("Cannot be negative", price)
        if price < 0.1 * self.__msrp:
            raise CostException("Too low", price)
        if price > self.__msrp:
            raise CostException("No price gouging", price)

        self.__currentPrice = price

    def __str__(self):
        return("{}: ${}, originally ${}".format(self.__name, self.__currentPrice, self.__msrp))


if __name__ == "__main__":
    product_name = input("Enter the product name: ")
    try:
        msrp = float(input("Enter the product msrp: "))
    except:
        print("msrp should be number")
        exit()

    try:
        product = ShoppingItem(product_name, msrp)
    except CostException as e:
        print(e)
        exit()
    except Exception as e:
        print(e)
        exit()

    try:
        sale_price = float(input("Enter the product sale price: "))
    except:
        print("sale price should be number")
        exit()

    try:
        product.setSalesPrice(sale_price)
    except CostException as e:
        print(e)
        exit()

    print(product)
