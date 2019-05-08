def display_heading(size, spaces):
	display_separator(size,spaces)
	title = str(size) + "X" + str(size) + " Times Table"
	print(get_word(title, (size+1) * spaces))
	display_separator(size,spaces)

def main():
	size = get_user_input()
	spaces = len(str(size*size)) + 2
	display_heading(size,spaces)
	display_table(size,spaces)
	display_separator(size,spaces)

def get_user_input():
	status = True
	while status:
		size = int(input("Size of the multiplication table : "))
		if size < 1 or size > 20:
			print("Size out of range, Enter 1 to 20")
		else:
			status = False
	return size

def display_separator(size, spaces):
	for i in range(0,(size+1)*spaces):
		print('-', end='')
	print('')

def get_number(num, spaces):
	spaces_to_add = spaces - len(str(num))
	return (' ' * spaces_to_add + str(num))

def get_word(words, spaces):
	spaces_to_add = (spaces - len(words)) // 2
	return (' ' * spaces_to_add + words + ' ' * spaces_to_add)

def get_row(num, size, spaces):
	return str(num) + " X " + str(size) + " | " + str(num * size)
	
def display_table(size, spaces):
	for i in range(1, size + 1):
		print(get_row(i, size, spaces))

if __name__ == "__main__":
	main()
