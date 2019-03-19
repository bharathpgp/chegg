def findLowest(listName):
    """
    Find lowest element in a list.
    Parameter: list of numbers.
    Returns: lowest number in the list of numbers.
    """
    lowest_element = listName[0]

    for index in range(1, len(listName)):
        if lowest_element > listName[index]:
            lowest_element = listName[index]

    return lowest_element


def computeAverage(listName):
    """
    Compute the average.
    Parameter: list of numbers.
    Returns: average of all the numbers in the list.
    """
    avg = sum(listName) / len(listName)
    return avg


def dropEveryNthElement(listName, N):
    """
    Drop every N th number in the list.
    Parameter: list of numbers.
    Returns: list of numbers with every N th number removed from the list.
    """
    new_list = list(listName)
    length = len(new_list)
    for index in range(0, length, N):
        new_list[index] = '-'

    while ('-' in new_list):
        new_list.remove('-')

    return new_list


def eliminateDuplicates(listName):
    """
    Eliminate duplicates.
    Parameter: list of numbers.
    Returns: list of numbers that does not contain any duplicate numbers in the list.
    """
    list_without_duplicate = []
    for number in listName:
        if number not in list_without_duplicate:
            list_without_duplicate.append(number)
    return list_without_duplicate


def duplicateNtimes(listName, count):
    """
    Duplicate all the numbers in the list to count times.
    Parameter: list of numbers.
    Returns: list of numbers with count times longer with each number contains count times in the list.
    """
    new_list = listName * count
    new_list.sort()
    return new_list


def displayMenu():
    """
    Print list of menu options.
    Parameter: None
    Returns: user choice.
    """
    print("Operations:")
    print("-----------")
    print("1. findLowest")
    print("2. computeAverage")
    print("3. dropEveryNthElement")
    print("4. eliminateDuplicates")
    print("5. duplicateNtimes")
    print("6. Exit")
    choice = int(input("User choice: "))
    return choice


def main():
    a = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    while True:

        choice = displayMenu()

        if choice == 1:
            print(findLowest(a))
        elif choice == 2:
            print(computeAverage(a))
        elif choice == 3:
            print(dropEveryNthElement(a, 3))
        elif choice == 4:
            print(eliminateDuplicates(a))
        elif choice == 5:
            print(duplicateNtimes(a, 3))
        elif choice == 6:
            exit(0)
        else:
            print("!!! Wrong choice selected, Enter correct choice:")


if __name__ == "__main__":
    main()
