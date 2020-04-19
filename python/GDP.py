
import pandas
import matplotlib.pyplot as plt

# reading from csv file
df = pandas.read_csv('GDP.csv')

# removing India, Japan and Korea data
df.drop(['India','Japan','Korea'], axis=1, inplace=True)

df.plot(x='Year')

# set title and legend for plot
plt.title("Asia, Hong Kong and mainland China GDP")
plt.legend()
plt.ylabel('GDP')

# show plot
plt.show()
