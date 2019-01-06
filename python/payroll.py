
fh = open("payroll.txt", 'r')
payTable = []

for myRecord in fh:
    myRecord = myRecord.rstrip("\r\n")
    payTable.append(myRecord.split(":"))

fh.close()
print(payTable)

# calculate weekly pay and print
for employee in payTable:
    weeklyPay = float(employee[2]) * float(employee[3])
    employee.append(weeklyPay)
    print(employee)
