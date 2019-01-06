
# function to calculate average of integers from a given input file
def csv_average(fileName: str):
    with open(fileName, 'r') as file:
        records = file.readlines()
        for data in records:
            data = data.strip('\n').split(',')
            data = list(map(int, data)) # convert string list to integer list
            print(sum(data)/len(data))

# main function
def main():
    csv_average("data.txt")


if __name__ == "__main__":
    main()
