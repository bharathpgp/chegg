#get student details from user
def fill_student_info(nofStudents):
    twoDlist = []
    for i in range(1, nofStudents + 1):
        stud_info = []
        studno = int(input("Student No: "))
        stud_info.append(studno)
        for j in range(1, 10 + 1):
            score = float(input("Assignment " + '{0:02d}'.format(j) + " Score: "))
            stud_info.append(score)
        twoDlist.append(stud_info)
    return twoDlist

#display the student information with formatted output
def display_student_info(twoDlist):
    for i in range(0, len(twoDlist)):
        print(
            '{0:6d} {1:7.02f} {2:7.02f} {3:7.02f} {4:7.02f} {5:7.02f} {6:7.02f} {7:7.02f} {8:7.02f} {9:7.02f} {10:7.02f}'.format(
                twoDlist[i][0], twoDlist[i][1], twoDlist[i][2], twoDlist[i][3], twoDlist[i][4], twoDlist[i][5],
                twoDlist[i][6], twoDlist[i][7], twoDlist[i][8], twoDlist[i][9], twoDlist[i][10]))

#determine minimum and maximum value for each assignments
def find_min_max(twoDlist):
    min_value = []
    max_value = []
    for col in range(1, 11):
        min = twoDlist[0][col]
        max = twoDlist[0][col]
        for j in range(1, len(twoDlist)):
            if twoDlist[j][col] < min:
                min = twoDlist[j][col]
            if twoDlist[j][col] > max:
                max = twoDlist[j][col]
        min_value.append(min)
        max_value.append(max)
    return min_value, max_value

#calculate total for each student
def calculate_total(twoDlist):
    totals = []
    for i in range(0, len(twoDlist)):
        tot = 0.0
        for col in range(1, 11):
            tot += twoDlist[i][col]
        totals.append(tot)
    return totals

#main function
if __name__ == "__main__":
    noofStud = input('Enter the number of students: ')
    twoDlist = fill_student_info(int(noofStud))
    display_student_info(twoDlist)
    (min, max) = find_min_max(twoDlist)
    print("The maximum scores for each assignment are:")
    print(max)
    print("The minimum scores for each assignment are:")
    print(min)
    totals = calculate_total(twoDlist)
    print("The total for each student:")
    print(totals)

# twoDlist = [['Sam', 45, 76, 88, 99, 72],
#            ["Ally", 66, 99, 84, 82, 96],
#            ["John", 58, 78, 90, 93, 70],
#            ["Marie", 77, 73, 85, 88, 92],
#            ["Bob", 81, 83, 85, 91, 88],
#            ["Grace", 92, 95, 87, 82, 90]]
# twoDlist = [[123456, 12.0, 34.0, 56.0, 76.0, 34.0, 54.0, 56.0, 89.0, 76.0, 54.0],
#             [543216, 45.0, 67.0, 87.0, 34.0, 12.0, 32.0, 43.0, 54.0, 12.0, 89.0]]

# print(twoDlist[0][1])
