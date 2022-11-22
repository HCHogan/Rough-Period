from math import factorial
import string
import re

s=input("输入算式")
s=s.replace("^","**")
d=re.findall(r"[0-9]*!",s)
for i in d:
    num=i.replace("!","")
    fact="factorial("+num+")"
    s=s.replace(i,fact)
print(eval(s))