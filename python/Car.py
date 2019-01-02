
# demonstrate car class with getter and setter methods
class Car:
    def __init__(self, loanNumber, maker, model, loanBalance):
        self.__loanNumber = loanNumber
        self.__maker = maker
        self.__model = model
        self.__loanBalance = loanBalance

    def setLoanNumber(self, loanNumber):
        self.__loanNumber = loanNumber

    def getLoanNumber(self):
        return self.__loanNumber

    def setMaker(self, maker):
        self.__maker = maker

    def getMaker(self):
        return self.__maker

    def setModel(self, model):
        self.__model = model

    def getModel(self):
        return self.__model

    def setLoanBalance(self, loanBalance):
        self.__loanBalance = loanBalance

    def getLoanBalance(self):
        return self.__loanBalance

    def displayLoanInfo(self):
        return "Car loan number : {0}, Maker : {1}, Model {2}, Loan Balance : ${3}".format(
            self.__loanNumber, self.__maker, self.__model, self.__loanBalance)


if __name__ == "__main__":
    mycar = Car(1121345670, "Tesla", "S", 5000)
    print(mycar.displayLoanInfo())
    mycar.setMaker("Ford")
    print(mycar.displayLoanInfo())
