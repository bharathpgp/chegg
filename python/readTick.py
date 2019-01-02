# dictionary to hold company data
data = {}

# read tickes from a file


def read_ticker():
    with open("ticks.txt", 'r') as file:
        ticks = file.readlines()
        for tick in ticks:
            symbol, cmpName, year = tick.strip(
                '\n').split('\t')  # split data with tab
            data[cmpName] = (symbol, year)

# main function


def main():
    read_ticker()
    print(data["Amazon.com, Inc."])
    print(data["Zebra Technologies Corporation"])
    print(data["BlackBerry Limited"])
    print(data["BlackBerry"])


if __name__ == "__main__":
    main()
