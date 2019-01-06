#!python
# define your own exceptions


class NumberTooSmallError(Exception):
    pass


class NumberTooBigError(Exception):
    message = '\nException: NumberTooBigError:\nYour number is too big. \nTry a smaller one!'


class NumberThreeError(Exception):
    def __init__(self):
        print (
            '\nException: ThreeNumberError:\nThree is not number ya\'re lookin\' for.\n')


class NumberFiveError(Exception):
    pass  # uncaught exception


# function that uses user-defined exceptions
def checkNumber(num):
    if(num == 3):
        raise NumberThreeError
    elif(num == 5):
        raise NumberFiveError
    elif(num < 99):
        raise (NumberTooSmallError, "Exception: given number is too small")
    elif(num > 99):
        raise (NumberTooBigError, "Exception: given number is too big")
    return num


# python try...catch block (why it is called try...except?)
while 1:
    try:
        usrInput = int(raw_input("\nPlease enter the magic number: "))
        print(checkNumber(usrInput))
    except NumberTooSmallError:
        print ("Number too small")
    except NumberTooBigError, e:
        print ("Number too big" + e.message)
    except NumberThreeError:
        print ('Ooops!')
    # here shuld be one more except block for catching
    # int(): val is not numeric exception
    # except ValueError:
        #print "Only numeric values are accepted"
    else:
        break
