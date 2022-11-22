import math
s=input("请输入算式")
s=s.replace("^","**")
i=1000
while i:
    s=s.replace(str(i)+"!",str(math.factorial(i)))
    i-=1
print(eval(s))