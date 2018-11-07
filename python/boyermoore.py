# Python3 Program for Boyer Moore String Matching Algorithm

NO_OF_CHARS = 256

def boyerMoor(string, size): 
	''' 
	The preprocessing function for Boyer Moore's Algo 
	'''
	# Initialize all occurence as -1 
	badChar = [-1]*NO_OF_CHARS 

	# Fill the actual value of last occurence 
	for i in range(size): 
		badChar[ord(string[i])] = i; 

	# retun initialized list 
	return badChar 

def search(txt, pat): 
	''' 
	A pattern searching function that uses Boyer Moore Algorithm
	'''
	m = len(pat) 
	n = len(txt) 

	# create the bad character list by calling 
	# the preprocessing function boyerMoor() 
	# for given pattern 
	badChar = boyerMoor(pat, m) 

	# s is shift of the pattern with respect to text 
	s = 0
	while(s <= n-m): 
		j = m-1

		# Keep reducing index j of pattern while 
		# characters of pattern and text are matching 
		# at this shift s 
		while j>=0 and pat[j] == txt[s+j]: 
			j -= 1

		# If the pattern is present at current shift, 
		# then index j will become -1 after the above loop 
		if j<0: 
			print("Pattern occur at shift = {}".format(s)) 
			s += (m-badChar[ord(txt[s+m])] if s+m<n else 1) 
		else: 
			s += max(1, j-badChar[ord(txt[s+j])]) 

# Driver program to test above funtion
def main(): 
	txt = "ycbabababaxbabababababa"
	pat = "cbababa"
	search(txt, pat)

if __name__ == '__main__': 
	main()