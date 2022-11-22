year=int(input("输入年"))
if year%4==0:
    if year%100!=0:
        print("是闰年")
    else:
        print("不是")
else:
    print("不是")

score=int(input("score?"))
if score>=60&score<70:
    print("hege")
if score<60:
    print("buhege")
if score>=70&score<90:
    print("llhc")
if score>=90:
    print("yzxp")