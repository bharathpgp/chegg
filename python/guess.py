# program to check the random number with user guess

import random as rand


def main():

    print("Welcome to my Guess the number program!")

    while True:
        # to generate random number between 1 and 10
        mynumber = rand.randint(1, 10)

        # to get user input
        guess = int(input("Please guess a number between 1 and 10: "))

        # condition to check user guess with random number
        if (guess == mynumber):
            print("You guessed it!")
            break
        else:
            print("Too high")


if __name__ == "__main__":
    main()
