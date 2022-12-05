# python大作业
## 一、问题描述及其分析
### 1.题目问题简述
    用字符串接收输入的表达式，计算该表达式
    要实现+（加）-（减）*（乘）/（整除）^（幂）!（阶乘）功能
### 2.问题分析
    设计一种算法，能将字符串转化为可计算的表达式，再将表达式结果计算出来。同时，当输入表达式不合法时，输出'error'。将中缀表达式转化为后缀表达式的时候需要用到栈，我们需要自己实现栈这种数据结构。
### 3.明确输入输出
    输入一个字符串，输出该字符串表达式计算结果。
    例如：
        输入： “1+2-3-8”
        输出：-8

        输入： “1+2*3+10/3”
        输出：10

        输入： “-1+2*3/4-2^4+5!+3^2+3!”
        输出：119

## 二、程序设计
    ->接受输入的字符串
    ->将字符串按照运算符和数字分开
    ->将中缀表达式转化为后缀表达式  ---(如果字符串不合法)--->输出‘error’
    ->计算后缀表达式    ---(如果字符串不合法)--->输出‘error’
    ->输出结果

## 三、测试

## 四、总结
### 1.代码
```py
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
            
s=input("输入算式\n")
s=re.split(r"([\+|\-|\*|/|^|!|(|)])",s)
#print(s)
if s[1]=='-':
    s.insert(0,'0')
#print(s)
s=midToSuc(s)
if s=='error':
    print("error")
else:
    print(calc(s))
```

### 2.分工情况
    Hank 90%
    BZB 10%
### 3.亮点，不足，如何改正
    没实现括号不知道为啥