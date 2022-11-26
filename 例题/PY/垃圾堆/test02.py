r=int(input("radius?"))
def calcc(r):
    return 2*r*3.14

def calcs(r):
    return r*r*3.14

def dis(x1,y1,x2,y2):
    return ((x1-x2)**2+(y1-y2)**2)**0.5

def calcsum(i,res):
    if i>100:
        return res
    return calcsum(i+1,res+i)

def fbnq(i,last1,last2):
    if i>3:
        return last2
    return fbnq(i+1,last2,last1+last2)

print(calcsum(1,0))
print(fbnq(2,0,1))