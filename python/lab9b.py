from tkinter import *

def data(fileName: str)->[[]]:
    employees = []
    with open(fileName, 'r') as dataFile:
        data = dataFile.readlines()
        for employee in data:
            # removing unwanted newlines and spaces in the data
            employee = employee.strip('\n').replace(' ', '').split(',')
            # convert hours worked colum into float
            employee[3] = float(employee[3])
            employees.append(employee)
    return employees

def process(employees: list)->dict:
    pay_rate = {"TECH": 9.50, "SHIP": 8.75, "ADMIN": 9.25, "SALES": 9.00}
    dept_payroll = {}

    for employee in employees:
        if dept_payroll.get(employee[2]) is None:
            dept_payroll[employee[2]] = [0.0, 0.0, 0.0]

    for employee in employees:

        if employee[0].find('Jan') is not -1:
            idx = 0
        elif employee[0].find('Feb') is not -1:
            idx = 1
        elif employee[0].find('Mar') is not -1:
            idx = 2

        data = dept_payroll.get(employee[2])
        data[idx] += employee[3] * pay_rate[employee[2]]
        dept_payroll[employee[2]] = data

    return dept_payroll


def lookup(payrolls: dict, key: str):
    payrolls = payrolls.get(key)
    if payrolls is None:
        return False
    else:
        payrolls.append(sum(payrolls))
        return payrolls


def menu(payrolls: dict):
    window = Tk()
    lblTitle = Label(window, text="Stiles Publishing", font=("Bold", 16))
    lblPayroll = Label(window, text="Payroll Summary", font=(14))
    lblDeptName = Label(window, text="Department Name: ")
    lblJan = Label(window, text="January")
    lblFeb = Label(window, text="February")
    lblMar = Label(window, text="March")
    lblTot = Label(window, text="TOTAL")
    txtJan = Entry(window, width=10)
    txtFeb = Entry(window, width=10)
    txtMar = Entry(window, width=10)
    txtTot = Entry(window, width=10)
    txtDeptName = Entry(window, width=15)
    txtDeptName.focus()

    def lookupClicked():
        deptname = txtDeptName.get()
        payroll = lookup(payrolls, deptname)
        txtJan.delete(0, 'end')
        txtFeb.delete(0, 'end')
        txtMar.delete(0, 'end')
        txtTot.delete(0, 'end')
        if payroll is not False:
            txtJan.insert(0, "{0:.2f}".format(payroll[0]))
            txtFeb.insert(0, "{0:.2f}".format(payroll[1]))
            txtMar.insert(0, "{0:.2f}".format(payroll[2]))
            txtTot.insert(0, "{0:.2f}".format(payroll[3]))

    btnLookup = Button(window, text="LOOKUP", command=lookupClicked)
    btnQuit = Button(window, text="QUIT", command=quit)

    window.geometry("300x400")

    lblTitle.grid(column=0, row=0, columnspan=2, sticky=E+W+N+S)
    lblPayroll.grid(column=0, row=1, columnspan=2,
                    padx=10, pady=10, ipadx=2, ipady=2)
    lblDeptName.grid(column=0, row=2, padx=10, pady=10, ipadx=2, ipady=2)
    txtDeptName.grid(column=1, row=2, padx=10, pady=10, ipadx=2, ipady=2)
    btnLookup.grid(column=0, row=3, padx=10, pady=10, ipadx=2, ipady=2)
    btnQuit.grid(column=1, row=3, padx=10, pady=10, ipadx=2, ipady=2)
    lblJan.grid(column=0, row=4, padx=10, pady=10, ipadx=2, ipady=2)
    txtJan.grid(column=1, row=4, padx=10, pady=10, ipadx=2, ipady=2)
    lblFeb.grid(column=0, row=5, padx=10, pady=10, ipadx=2, ipady=2)
    txtFeb.grid(column=1, row=5, padx=10, pady=10, ipadx=2, ipady=2)
    lblMar.grid(column=0, row=6, padx=10, pady=10, ipadx=2, ipady=2)
    txtMar.grid(column=1, row=6, padx=10, pady=10, ipadx=2, ipady=2)
    lblTot.grid(column=0, row=7, padx=10, pady=10, ipadx=2, ipady=2)
    txtTot.grid(column=1, row=7, padx=10, pady=10, ipadx=2, ipady=2)

    window.mainloop()
    return

def quit():
    exit()

def main():
    employees = data("employeeHours.txt")
    payrolls = process(employees)
    menu(payrolls)
    return

if __name__ == "__main__":
    main()