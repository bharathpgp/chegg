current_unit = 0

units = {
    0: ("Celsius", "C"),
    1: ("Fahrenheit", "F"),
    2: ("Kelvin", "K"),
    5: ("Rankine", "R")
}


def report():
    unit, _ = units[current_unit]
    print("Current units in {0}".format(unit))


def menu():
    print()
    print("Main Menu")
    print("---------")
    print("1 - Process a new data file")
    print("2 - Choose units")
    print("3 - Edit room filter")
    print("4 - Show summary statistics")
    print("5 - Show temperature by date and time")
    print("6 - Show histogram of temperatures")
    print("7 - Quit")
    print()
    choice = int(input("What is your choice? "))
    return choice


def changeUnits():
    print("Choose new units:")
    values = []
    for key in units.keys():
        unit, _ = units[key]
        values.append(key)
        print("{0} - {1}".format(key, unit))
    try:
        usrVal = int(input("Which unit?\n"))
        if usrVal not in values:
            print("Please choose a unit from the list")
            changeUnits()
        else:
            global current_unit
            current_unit = usrVal
    except ValueError:
        print("*** Please enter a number only ***")
        changeUnits()

def main():
    while True:
        choice = menu()

        if (2 == choice):
            report()
            changeUnits()
    return

if __name__ == "__main__":
    main()
