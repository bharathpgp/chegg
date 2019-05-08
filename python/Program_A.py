if __name__ == "__main__":
	avg = 0.0
	tot = 0.0
	cnt = 0
	while True:
		num=int(input("Enter number: "))
		if 0 == num:
			break
		else:
			tot += num
			cnt += 1
	avg = tot / cnt
	print("Average of entered numbers: " + str(avg))
