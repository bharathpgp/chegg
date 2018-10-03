#Unicode for each grocery items to display in console
unicode = {"pizza": 127829, "carrot": 129365, "apple": 127822, "peach": 127825, "egg": 129370,
           "roasted sweet potato": 127840, "pineapple": 127821, "cookie": 127850,
           "bread": 127838, "lemon": 127819, "banana": 127820, "avocado": 129361}

#lookup specific grocery item
def lookup(d, item):						#defining lookup function.
    if d.get(item) is not None:
        print(item, end=" ")
        for i in range(0, d[item]):
            print(chr(unicode[item]), end="")
        print("")

#add item to grocery
def addItem(d, item):					    #defining addItem function.
    if d.get(item) is None:
        d[item] = 1
    else:
        d[item] += 1

#remove item from grocery
def subItem(d, item):					    #defining Subitem function.
    if d.get(item) is not None:
        if (1 == d[item]):
            del d[item]
        else:
            d[item] -= 1

#display all available grocery items
def show(d):								#defining show function.
    for item, cnt in d.items():
        print(item, end=" ")
        for i in range(0, cnt):
            print(chr(unicode[item]), end="")
        print("")

#main function to read user input
if __name__ == "__main__":
    grocery = {}
    while (1):							#Always true while loop.
        cmd = input("=> ")
        cmd = cmd.lower()
        if "show" == cmd:
            show(grocery)
        elif "quit" == cmd:
            exit()
        else:
            (cmd, item) = cmd.split()
            if "add" == cmd:
                addItem(grocery, item)
            elif "sub" == cmd:
                subItem(grocery, item)
            elif "lookup" == cmd:
                lookup(grocery, item)
