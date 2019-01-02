
# calculate new salary for given pay percentage and old salary
def calculateNewSalary(oldSalary: float, payPercent: float) -> float:
    return oldSalary + oldSalary * payPercent / 100

# read employees salary details from file
def readEmployeeData() -> list:
    with open("CH3_Ex5Data.txt", 'r') as inFile:
        return inFile.readlines()

# write new employee salary details into file
def writeNewEmployeeData(employees: list):
    with open("CH3_Ex5Output.dat", 'w') as outFile:
        for employee in employees:
            employee = employee.strip('\n').split(' ')
            oldSalary = float(employee[2])
            payPercent = float(employee[3])
            newSalary = calculateNewSalary(oldSalary, payPercent)
            outFile.write("{0} {1} {2:.2f}\n".format(
                employee[1], employee[0], newSalary))

# main program to demonstrate employee salary hike
def main():
    employees = readEmployeeData()
    writeNewEmployeeData(employees)


if __name__ == "__main__":
    main()
