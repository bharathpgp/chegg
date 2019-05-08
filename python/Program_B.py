if __name__ == "__main__":
	max = 0
	while True:
		num=int(input("Enter number: "))
		if 0 == num:
			break
		else:
			if num > max:
				max = num
	print("Max integer: " + str(max))
