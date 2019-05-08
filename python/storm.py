class Storm:
    def __init__(self, name="default"):
        self.name = name


class TropicalStorm(Storm):
    def __init__(self, peakws=0, peakrf=0, year=1990, name="default"):
        Storm.__init__(self, name)
        self.year = year
        self.peakws = peakws
        self.peakrf = peakrf

    def __str__(self):
        return "I am Tropical Strom named " + self.name + ". I have peak winds of " + str(
            self.peakws) + " mph, peak rain fall of " + str(self.peakrf) + " inches per hour in the year " + str(
            self.year)

    def getName(self):
        return self.name

    def setName(self, name):
        self.name = name

    def getYear(self):
        return self.year


class Hurricane(TropicalStorm):
    def __init__(self, peakrf=0, peakws=0, year=1990, name="default", category=0):
        TropicalStorm.__init__(self, peakws, peakrf, year, name)
        self.category = category

    def __str__(self):
        return "I am category " + str(self.category) + " Hurrican named " + self.name + ". I have peak winds of " + str(
            self.peakws) + " mph, peak rain fall of " + str(self.peakrf) + " inches per hour in the year " + str(
            self.year)

    def getCategory(self):
        return category

    def setCategory(self, category):
        if (category > 5):
            self.category = 5
        elif (category < 0):
            self.category = 0
        else:
            self.category = category

    def getWindSpeed(self):
        return peakws


if __name__ == "__main__":
    s1 = TropicalStorm()
    print(s1)
    s2 = TropicalStorm(20, 80, 2007, 'Bob')
    print(s2)
    print(s2.getName())
    print(s2.getYear())
    s3 = Hurricane()
    print(s3)
    s4 = Hurricane(12, 200, 2017, 'Irma', 5)
    print(s4)
    s5 = TropicalStorm(20, 20, 2012, 'Tony')
    print(s5)