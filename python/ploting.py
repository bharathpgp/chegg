# Learn about API authentication here: https://plot.ly/python/getting-started
# Find your api_key here: https://plot.ly/settings/api

import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly

plotly.tools.set_credentials_file(username='bharathpgp', api_key='uYE3aoJd4ZTyDOCWO8JU')
dictionary = plt.figure()

D = {u'Label0':26, u'Label1': 17, u'Label2':30}

plt.bar(range(len(D)), D.values(), align='center')
plt.xticks(range(len(D)), D.keys())

plot_url = py.plot_mpl(dictionary, filename='mpl-dictionary')
