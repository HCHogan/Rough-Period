lst=[]
lst.extend([78, 93, 66, 83, 100, 95, 77, 93, 85, 98])
print(lst[6])
print(lst[0:5])
lst.insert(7,59)
num=93
print(lst.count(num))
print(num in lst)
print(lst.index(100))
lst[lst.index(59)]+=1
lst.sort()
print(max(lst)," ",min(lst))
lst.reverse()
print(lst.pop(len(lst)-1))
lst.append(83)
lst.remove(83)
lst1=[78,91]
lst2=[84,92,65]
print(lst1+lst2)
lst1=[78,91]
lst2=lst1*5
print(lst2)
lst.clear()
lst1=lst2.copy()
lst1[1]=2
print(lst1," ",lst2)