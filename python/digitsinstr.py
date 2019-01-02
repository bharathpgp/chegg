def sumOfDigits(string):
    sum = 0
    for char in string:
        if char in ('0', '1', '2', '3', '4', '5', '6', '7', '8', '9'):
            sum += int(char)
    return sum


def main():
    print(sumOfDigits("Geneva Convention"))
    print(sumOfDigits("R2D2"))
    print(sumOfDigits("Remy Martin 1984"))


if __name__ == "__main__":
    main()
