
# Set of integers
A = [-1,2,3,-4,5,8,7,10,-9,0,100,1000,-234]
j = 0
# reoder the elements in A such that all negative integers positioned before all positive integers
for i in range(0, len(A)):
    if A[i] < 0:
        A[j], A[i] = A[i], A[j] # swapping the negative integer before positive integer
        j += 1
print(A)    # display the reordered elements