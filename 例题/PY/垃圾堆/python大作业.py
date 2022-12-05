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
        if self.idx==0:
            return 'error'
        self.idx=self.idx-1
        return self.items[self.idx]
        
    def top(self):
        return self.items[self.idx-1]
    
    def clear(self):
        self.idx=0
        return 0
    
    def size(self):
        return self.idx

def operate(x,y,op):
    if op=='+':
        return x+y
    if op=='-':
        return x-y
    if op=='*':
        return x*y
    if op=='/':
        return x//y
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
                if Stemp.pop()=='error':
                    return 'error'
            Stemp.push(i)
    while(not Stemp.empty()):
        reSuc.append(Stemp.top())
        if Stemp.pop()=='error':
            return 'error'
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
            temp1=Sdigital.pop()
            if temp1=='error':
                return 'error'
            else:
                temp1=int(temp1)
            Sdigital.push(myFactorial(temp1,1))
        else:   
            temp2=Sdigital.pop()
            temp1=Sdigital.pop()
            if temp1=='error' or temp2=='error':
                return 'error'
            else:
                temp1=int(temp1)
                temp2=int(temp2)
            Sdigital.push(operate(temp1,temp2,i))
    if Sdigital.size()>1:
        return 0.5
    return Sdigital.pop()
            
s=input("算式来\n")
s=re.split(r"([\+|\-|\*|/|^|!|(|)])",s)
print(s)
if s[1]=='-':
    s.insert(0,'0')
print(s)
s=midToSuc(s)
if s=='error':
    print("error")
else:
    print(calc(s))