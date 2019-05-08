
def display_heading(size, spaces):
	display_separator(size,spaces)
	title = str(size) + "X" + str(size) + " Times Table"
	print(get_word(title, (size+1) * spaces))
	print(get_row(0, size, spaces))
	display_separator(size,spaces)

def main():
	size = get_user_input()
	spaces = len(str(size*size)) + 2
	display_heading(size,spaces)
	display_table(size,spaces)
	display_separator(size,spaces)

def get_user_input():
	size = int(input("Enter the size of the multiplication table (1-20): "))
	if size < 1 or size > 20:
		print("Table size should be between 1 and 20.")
		size = int(input("Please try again: "))
	return size

def display_separator(size, spaces):
	for i in range(0,(size+2)*spaces):
		print('-', end='')
	print('')

def get_number(num, spaces):
	spaces_to_add = spaces - len(str(num))
	return (' ' * spaces_to_add + str(num))

def get_word(words, spaces):
	spaces_to_add = (spaces - len(words)) // 2
	return (' ' * spaces_to_add + words + ' ' * spaces_to_add)

def get_row(num, size, spaces):
	if 0 == num:
		row = ' ' * (spaces + 3)
		for i in range(1, size + 1):
			row += get_number(i, spaces)			
	else:
		row = get_number(num, spaces) + " | "
		for i in range(1, size + 1):
			ans = num * i
			row += get_number(ans, spaces)
	return  row
	
def display_table(size, spaces):
	for i in range(1, size + 1):
		print(get_row(i, size, spaces))

if __name__ == "__main__":
	main()
