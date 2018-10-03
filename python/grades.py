#!/usr/bin/python
import matplotlib.pyplot as plt

# path of the students grade file
file = '/tmp/grades.txt'

# initial count of each grade
ranks = { 'A': 0, 'B': 0, 'C': 0, 'D': 0, 'F': 0 }
boundry = { 10: 'A', 9: 'A', 8: 'B', 7:'C', 6: 'D' }

# readind grades from file and stored into list
data = [line.strip() for line in open(file, 'r')]

# calculating number of students in each grade
for studGrade in data:
    grades = list(map(int, studGrade.split(',')))
    avg = sum(grades) / len(grades)
    mark = boundry.get(int(avg/10),'F')
    ranks[mark] += 1

# drawing bar chart
(fig, ax) = plt.subplots()
ax.set_title('Student Grades')
ax.set_xlabel('Grade Category')
ax.set_ylabel('Number of Students')
ax.set_ylim(0, max(ranks.values()))
ax.bar(ranks.keys(), ranks.values())
plt.show()
