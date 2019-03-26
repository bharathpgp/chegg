import random as rand
import datetime as dt


class Account:
    lastAcctNumberUsed = 0
    numSavingsAccts = 0
    numCheckingAccts = 0
    savingTotalAssets = 0.0

    def __init__(self, tmpAcctType: str(), tmpDateOpened: dt.date, tmpOpenBalance: int):
        self.__acctType = tmpAcctType
        self.__dateOpened = tmpDateOpened
        self.__openBalance = tmpOpenBalance
        self.__acctNumber = rand.randint(100000, 999999)
        self.__curBalance = tmpOpenBalance

    def getAcctType(self)->str:
        """
        Returns: account type.
        """
        return self.__acctType

    def getOpenBalance(self) -> float:
        """
        Returns: Opening balance.
        """
        return self.__openBalance

    def getCurBalance(self)->float:
        return self.__curBalance

    def getDateOpened(self) ->dt.date:
        return self.__dateOpened

    def getAcctNum(self)->int:
        return self.__acctNumber

    def __getNumSavingsAccts(self)->int:
        pass

    def __getNumCheckingAccts(self)->int:
        pass

    def __getTotalAssets(self)->float:
        pass

    def __setCurBalance(self, newBalance: float):
        self.__curBalance = newBalance

    def __updateTotalAssets(self):
        pass

    def __str__(self):
        """
        Return account details.
        """
        return "Account Number: {}\nAccount Type: {}\nDate Opened: {}\nOpening Balance: {}\nCurrent Balance:{}".format(self.__acctNumber, self.__acctType, self.__dateOpened, self.__openBalance, self.__curBalance)


class CDSavingsAcct(Account):
    CD_Interest_Rate = 10.0

    def __init__(self, maturityDate: dt.date):
        self.__maturityDate = maturityDate
        pass

    def closeAcct(self):
        pass

    def computeInterest(self):
        curBalance = self.getCurBalance()
        interestEarned = curBalance * self.CD_Interest_Rate / 100
        curBalance += interestEarned
        self.__setCurBalance(curBalance)

    def __str__(self):
        return super().__str__(self)


class CheckingAcct(Account):
    def __init__(self, totalDepositAmts: float, totalWithdrawalAmts: float):
        self.totalDepositAmts = totalDepositAmts
        self.totalWithdrawalAmts = totalWithdrawalAmts
        super().__init__()

    def deposit(self, amt: float):
        self.totalDepositAmts += amt
        self.__updateCurrentBalance(amt)

    def withdrawal(self, amt: float):
        pass

    def __updateCurrentBalance(self, amt: float):
        curBalance = self.getCurBalance()
        curBalance += amt
        self.__setCurBalance(curBalance)

    def __str__(self):
        return super().__str__(self)


if __name__ == "__main__":
    bharath = Account("Saving", "12.5.2018", 5000.00)
    print(bharath)
