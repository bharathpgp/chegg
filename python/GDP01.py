

import matplotlib.pyplot as plt
import csv

years = []
asia_gdp = []
china_gdp = []
hk_gdp = []

# reading from csv file
with open('GDP.csv', 'r') as gdpfile:
    reader = csv.reader(gdpfile, delimiter=',')
    next(reader)
    for row in reader:
        years.append(row[0])
        asia_gdp.append(row[1])
        china_gdp.append(row[2])
        hk_gdp.append(row[3])

plt.plot(years, asia_gdp, color='blue', label='Asia', linestyle='dashed')
plt.plot(years, china_gdp, color='red', label='China', linestyle='dotted')
plt.plot(years, hk_gdp, color='yellow', label='HK')

plt.xlabel('Year')
plt.ylabel('GDP')
plt.title('Asia, Hong Kong and mainland China GDP')

plt.legend()
plt.show()
