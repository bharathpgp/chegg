
# print header for forwarding database(FDB)
def printHeader(outFile: str):
    outFile.write("-------------------------------------------------\n")
    outFile.write("| Indx | Host | Port |\n")
    outFile.write("-------------------------------------------------\n")

# print forwarding database(FDB)
def printFDB(outFile: str, fdb: dict):
    sno = 1
    printHeader(outFile)
    for port, mac in fdb.items():
        outFile.write("|{0}|{1}|{2}|\n".format(sno, mac, port))
        sno += 1
    outFile.write("\n")


# number of ports in the bridge
N = int(input("Number of ports in the bridge: "))
if N > 8:
    print("Number of ports should be less than 9")
    exit()
fileName = input("Enter input file name: ")

fdb = {}    # store MAC and its incoming port number

with open("fdb.txt", 'w') as outFile:

    with open(fileName, 'r') as file:
        frames = file.readlines()
        for frame in frames:
            frame = frame.strip('\n')
            try:
                src, dest, port = frame.split(" ")
                if int(port) > N:
                    continue
            except ValueError:
                continue

            if fdb.get(port) is None:
                fdb[port] = src
                outFile.write(
                    "Action: add to FDB (index {0}); forward to all out ports: \n".format(len(fdb)))
            else:
                index = list(fdb.keys()).index(port)
                outFile.write("Action: found at index {0}(no update); forward to port: \n".format(
                    index + 1))

            printFDB(outFile, fdb)
