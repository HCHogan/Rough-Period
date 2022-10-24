#!/usr/bin/env python3
def trans(n):
    a=int(n%2)
    if(n==2):
        print('1')
    else:
        trans(n/2)
    print(a)
n=int(input("请输入n的值: "))
trans(n)