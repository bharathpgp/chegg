#!/usr/bin/python
import matplotlib.pyplot as plt

# path of the students grade file

file = '/tmp/grades.txt'

# initial count of each grade

ranks = {
    'A': 0,
    'B': 0,
    'C': 0,
    'D': 0,
    'F': 0,
    }

# readind grades from file and stored into list

data = [line.strip() for line in open(file, 'r')]

# calculating number of students in each grade

for studGrade in data:
    grades = list(map(int, studGrade.split(',')))
    totGrade = 0
    for grade in grades:
        totGrade += grade
    avg = totGrade / 5.0
    if avg >= 90 and avg <= 100:
        ranks['A'] += 1
    elif avg >= 80 and avg <= 89:
        ranks['B'] += 1
    elif avg >= 70 and avg <= 79:
        ranks['C'] += 1
    elif avg >= 60 and avg <= 69:
        ranks['D'] += 1
    else:
        ranks['F'] += 1

# drawing bar chart

(fig, ax) = plt.subplots()
ax.set_title('Student Grades')
ax.set_xlabel('Grade Category')
ax.set_ylabel('Number of Students')
ax.set_ylim(0, max(ranks.values()))
ax.bar(ranks.keys(), ranks.values())
plt.show()
