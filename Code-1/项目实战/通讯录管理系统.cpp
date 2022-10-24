#include<iostream>
#include<string>
using namespace std;
struct person{
    string name;
    int sex;
    int age;
    string phone;
    string address;
};

struct addressBook{
    person pArray[1000];
    int Size;
};

void showMenu(){
    cout<<"1 添加联系人"<<endl;
    cout<<"2 显示联系人"<<endl;
    cout<<"3 删除联系人"<<endl;
    cout<<"4 查找联系人"<<endl;
    cout<<"5 修改联系人"<<endl;
    cout<<"6 清空联系人"<<endl;
    cout<<"0 退出通讯录"<<endl;
}

void addPerson(addressBook*abs){
    if(abs->Size==1000){
        cout<<"通讯录已满，无法添加！"<<endl;
        return;
    }
    cout<<"请输入姓名： "<<endl;
    string name;
    cin>>name;
    abs->pArray[abs->Size].name=name;
    cout<<"请输入性别： "<<endl;
    cout<<"1---男"<<endl;
    cout<<"2---女"<<endl;
    int sex;
    cin>>sex;
    abs->pArray[abs->Size].sex=sex;
    cout<<"请输入年龄： "<<endl;
    int age;
    cin>>age;
    abs->pArray[abs->Size].age=age;
    cout<<"请输入号码： "<<endl;
    string phone;
    cin>>phone;
    abs->pArray[abs->Size].phone=phone;
    cout<<"请输入住址： "<<endl;
    string address;
    cin>>address;
    abs->pArray[abs->Size].address=address;
    abs->Size++;
    cout<<"添加成功！"<<endl;
}

void showPerson(addressBook*abs){
    for(int i=0;i<(abs->Size);i++){
        cout<<"姓名："<<abs->pArray[i].name<<endl;
        cout<<"性别："<<abs->pArray[i].sex<<endl;
        cout<<"年龄："<<abs->pArray[i].age<<endl;
        cout<<"电话："<<abs->pArray[i].phone<<endl;
        cout<<"地址："<<abs->pArray[i].address<<endl;
    }
}
int IsExist(string name,addressBook*abs){
    int i;
    for(i=0;i<(abs->Size);i++){
        if(name==abs->pArray[i].name)return i;
        else return -1;
    }
}
void deletePerson(addressBook*abs){
    cout<<"请输入要删除联系人的姓名："<<endl;
    string name;
    cin>>name;
    if(IsExist(name,abs)!=-1){
        int m=IsExist(name,abs);
        for(int i=m;i<=(abs->Size);i++){
            abs->pArray[i]=abs->pArray[i+1];
        }
        abs->Size--;
        cout<<"删除成功！"<<endl;
    }
    else{
        cout<<"查无此人！"<<endl;
    }
}

void searchPerson(addressBook*abs){
    cout<<"请输入想要查找联系人的姓名："<<endl;
    string name;
    cin>>name;
    int m=IsExist(name,abs);
    if(m==-1){
        cout<<"查无此人！"<<endl;
    }
    else{
        cout<<abs->pArray[m].name<<"  ";
        cout<<abs->pArray[m].sex<<"  ";
        cout<<abs->pArray[m].age<<"  ";
        cout<<abs->pArray[m].phone<<"  ";
        cout<<abs->pArray[m].address<<endl;
    }
}
void modifyPerson(addressBook*abs){
    cout<<"请输入要修改的姓名： "<<endl;
    string name;
    cin>>name;
    int m;
    m=IsExist(name,abs);
    if(m==-1)cout<<"查无此人！";
    else{
        cout<<"请输入姓名： "<<endl;
        string name;
        cin>>name;
        abs->pArray[m].name=name;
        cout<<"请输入性别： "<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        int sex;
        cin>>sex;
        abs->pArray[m].sex=sex;
        cout<<"请输入年龄： "<<endl;
        int age;
        cin>>age;
        abs->pArray[m].age=age;
        cout<<"请输入号码： "<<endl;
        string phone;
        cin>>phone;
        abs->pArray[m].phone=phone;
        cout<<"请输入住址： "<<endl;
        string address;
        cin>>address;
        abs->pArray[m].address=address;
        abs->Size++;
        cout<<"修改成功！"<<endl;
    }
}
void clear(addressBook*abs){
    abs->Size=0;
}

int main(){
    addressBook abs;
    abs.Size=0;
    int a;
    while(1){
        showMenu();
        cin>>a;
        switch(a){
            case(1):addPerson(&abs);break;
            case(2):showPerson(&abs);break;
            case(3):deletePerson(&abs);break;
            case(4):searchPerson(&abs);break;
            case(5):modifyPerson(&abs);break;
            case(6):clear(&abs);break;
            case(0):cout<<"欢迎下次使用"<<endl;break;return 0;
        }
    }
}