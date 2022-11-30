import re

class stack:
    def __init__(self):
        self.items = []
        self.idx=0
    
    def empty(self):
        if self.idx==0:
            return 1
        return 0
    
    def push(self,val):
        if self.idx>=len(self.items):
            self.items.append(0)
        self.items[self.idx]=val
        self.idx=self.idx+1
        return 0
    
    def pop(self):
        self.idx=self.idx-1
        return self.items[self.idx]
        
    def top(self):
        return self.items[self.idx-1]
    
    def clear(self):
        self.idx=0
        return 0

def operate(x,y,op):
    if op=='+':
        return x+y
    if op=='-':
        return x-y
    if op=='*':
        return x*y
    if op=='/':
        return x/y
    if op=='^':
        return x**y
    return -1
    
def myFactorial(x,res):
    if x==0:
        return res
    return myFactorial(x-1,res*x)

def priority(op):
    if(op=='-' or op=='+'):
        return 1
    if(op=='*' or op=='/'):
        return 2
    if(op=='^'):
        return 3
    if(op=='!'):
        return 4
    if(op==''):
        return -1
    return 0

def midToSuc(s):
    reSuc=[]
    Stemp=stack()
    for i in s:
        if priority(i)==-1:
            continue
        elif priority(i)==0:
            reSuc.append(i)
        elif i=='(':
            Stemp.push(i)
        elif i==')':
            while Stemp.top()!='(':
                print("hh")
                reSuc.append(Stemp.pop())
        else:
            while Stemp.empty()==0 and priority(Stemp.top()) >= priority(i):
                reSuc.append(Stemp.top())
                Stemp.pop()
            Stemp.push(i)
    while(not Stemp.empty()):
        reSuc.append(Stemp.top())
        Stemp.pop()
    return reSuc

'''
def sucToMid(s):
    Sdigits=stack()
    Soperators=stack()
    s=list(reversed(s))
    for i in s:
        if 1<=priority(i)<=4:
'''          

def calc(reSuc):
    Sdigital=stack()
    for i in reSuc:
        if priority(i)==0:
            Sdigital.push(i)
        elif i=='!':
            temp1=int(Sdigital.pop())
            Sdigital.push(myFactorial(temp1,1))
        else:   
            temp2=int(Sdigital.pop())
            temp1=int(Sdigital.pop())
            Sdigital.push(operate(temp1,temp2,i))
    return Sdigital.pop()
            
s=input("算式来\n")
s=re.split(r"([\+|\-|\*|/|^|!|(|)])",s)
print(s)
print(midToSuc(s))
print(calc(midToSuc(s)))