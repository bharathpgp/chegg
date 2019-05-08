from tkinter import Tk, Label, Button, Entry, END

employees = []

class Employee:
	def __init__(self, empno, name, addr, hwage, hworked):
		self.empno = empno
		self.name = name
		self.addr = addr
		self.hwage = hwage
		self.hworked = hworked

	def calc_salary(self):
		self.gpay = float(self.hwage) * float(self.hworked)
		self.netpay = self.gpay - self.gpay * 0.20 - self.gpay * 0.075
		return self.netpay

class MyFirstGUI:
	def __init__(self, master):
		self.cnt = 0
		self.master = master
		master.title("Fluff Shuffle Electronics")

		self.lEmpNo = Label(master, text="Emp Number: ")
		self.txtEmpNo = Entry(master, validate="key", text="Hello")
		self.lName = Label(master, text="Name: ")
		self.txtName = Entry(master, validate="key")
		self.lAddr = Label(master, text="Address: ")
		self.txtAddr = Entry(master, validate="key")
		self.lhw = Label(master, text="Hourly Wage: ")
		self.txthw = Entry(master, validate="key")
		self.lhwkd = Label(master, text="Hours Worked: ")
		self.txthwkd = Entry(master, validate="key")
		self.lNetpay = Label(master, text="Net Pay: ")
		self.txtNetpay = Entry(master, validate="key")

		self.btnNext = Button(master, text="Next Employee", command=lambda: self.update("next"))
		self.btnClose = Button(master, text="Close", command=master.quit)

		self.lEmpNo.grid(row=0, column=0)
		self.txtEmpNo.grid(row=0, column=1)
		self.lName.grid(row=1, column=0)
		self.txtName.grid(row=1, column=1)
		self.lAddr.grid(row=2, column=0)
		self.txtAddr.grid(row=2, column=1)
		self.lhw.grid(row=3, column=0)
		self.txthw.grid(row=3, column=1)
		self.lhwkd.grid(row=4, column=0)
		self.txthwkd.grid(row=4, column=1)
		self.lNetpay.grid(row=5, column=0)
		self.txtNetpay.grid(row=5, column=1)
		self.btnNext.grid(row=6, column=0)
		self.btnClose.grid(row=6, column=1)

		self.update("next")

	def greet(self):
		print("Greetings!")

	def update(self, method):
		if method == "next":
			print(employees[self.cnt].name)
			emp = employees[self.cnt]
			self.txtEmpNo.delete(0, END)
			self.txtEmpNo.insert(0, emp.empno)
			self.txtName.delete(0, END)
			self.txtName.insert(0, emp.name)
			self.txtAddr.delete(0, END)
			self.txtAddr.insert(0, emp.addr)
			self.txthw.delete(0, END)
			self.txthw.insert(0, emp.hwage)
			self.txthwkd.delete(0, END)
			self.txthwkd.insert(0, emp.hworked)
			self.txtNetpay.delete(0, END)
			self.txtNetpay.insert(0, emp.calc_salary())
			self.cnt += 1
			self.cnt = self.cnt % len(employees)

if __name__ == "__main__":
	file_ref = open("emp-payroll-data.txt", 'r')
	line = file_ref.readline()
	while line:
		line = line.strip('\n')
		emp_data = line.split(',')
		print(emp_data)
		emp = Employee(emp_data[0], emp_data[1], emp_data[2], emp_data[3], emp_data[4])
		employees.append(emp)
		line = file_ref.readline()
	root = Tk()
	my_gui = MyFirstGUI(root)
	root.mainloop()
