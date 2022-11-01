fruits=['apple','banana','grape']
fruits.append('orange')
fruits.insert(1,'pear')
del fruits[fruits.index('grape')]
print(fruits)
lst1=[0.5,1.6,8.5,6.4,7.2,5,3.6,5.5,4.1,10]
del lst1[lst1.index(max(lst1))]
del lst1[lst1.index(min(lst1))]
print(sum(lst1)/len(lst1))
from math import pi
print("{hehe} is {hehe}".format(hehe='nmsl'))
print("{0:.2f}".format(pi))