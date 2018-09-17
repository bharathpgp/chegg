class Series(object):
	
	def __init__(self, data, name=""):
		self.data = data
		self.name = name		

	def __add__(self, other):
		l1 = self.data
		l2 = other.data	
		return Series([(a + b) for a, b in zip(l1, l2)])

	def __sub__(self, other):
		l1 = self.data
		l2 = other.data	
		return Series([(a - b) for a, b in zip(l1, l2)])

	def __mul__(self, other):
		l1 = self.data
		l2 = other.data	
		return Series([(a * b) for a, b in zip(l1, l2)])

	def __div__(self, other):
		l1 = self.data
		l2 = other.data	
		return Series([(a / b) for a, b in zip(l1, l2)])

	def __repr__(self):
		return "Series()"

	def __str__(self):
		return str(self.data) + str(self.name)

class Dataframe(object):
	def __init__(self,data):
		self.data = data
	
#	def __getitem__(self, index):
		
#	def col(name):
		
#	def row(index):

if __name__ == "__main__":
	s1 = Series([1,2,3,4,5], "Rank")
	s2 = Series([1,2,3,4,5])
	print(s1 + s2)
	print(s1 - s2)
	print(s1 * s2)
	print(s1 / s2)
