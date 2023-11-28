import pandas as pd
import numpy as np
data = pd.read_csv('kosdaq.csv')
data_size = len(data)
print(data_size)

data2 = []
for i in range(0,data_size-1):#
  b = data.loc[i,'date']
  if len(b) == 10:
    data2.append(b)
  else:
    a = ""
    c = ""
    # d = ""
    # arr =[4,2,2]
    x = b[:5]#2000-
    for j in range(5,len(b)):
      if b[j] != '-':
        a += b[j]
      else:
        c = a
        a = ""
    if len(a) < 2:
      a = "0"+a
    if len(c) < 2:
      c = "0"+c
    x = x+c+"-"+a
    data2.append(x)

df2 = pd.DataFrame(data2)
df2.to_csv('new_date.csv', index=False)
