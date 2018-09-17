import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly

#plotly.tools.set_credentials_file(username='bharathpgp', api_key='uYE3aoJd4ZTyDOCWO8JU')
dictionary = plt.figure()

file="/tmp/grades.txt"
rank = {'A':0,'B':0,'C':0,'D':0,'F':0}
data = [line.strip() for line in open(file, 'r')]
print(data)
grades = []
for marks in data:
 row = list(map(int,marks.split(',')))
 tot = 0
 for mark in row:
  tot += mark
 avg = tot / 5.0
 print(avg)
 if avg >= 90 and avg <= 100:
  rank['A'] += 1
 elif avg >= 80 and avg <= 89:
  rank['B'] += 1
 elif avg >= 70 and avg <= 79:
  rank['C'] += 1
 elif avg >= 60 and avg <= 69:
  rank['D'] += 1
 else:
  rank['F'] += 1

#plt.bar(rank.keys(), rank.values(), align='center')
#plt.xticks(range(len(rank)), rank.keys())

fig, ax = plt.subplots()
ax.bar(rank.keys(), rank.values())

ax.set_ylim(0,10)
ax.set_ylabel('Frequency')
ax.set_title('Student Grade')
#ax.set_xticklabels()

plt.show()
#plt.xticks(range(len(rank)), rank.keys())

#plot_url = py.plot_mpl(dictionary, filename='mpl-dictionary')
 
#if __name__ == "__main__":
	
