lst=[1,2,3,4,5]
del lst[1]
print(lst[1])
print(lst[1:4])
lst[1:2]=[99,99,99]
print(lst)
lst[1:4]=[99]
print(lst)
lst.append([4])
print(lst)
lst1=[1]
lst1=lst.copy()
print(id(lst))
print(id(lst1))
