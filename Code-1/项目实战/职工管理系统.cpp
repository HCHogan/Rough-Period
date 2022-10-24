#include<iostream>  
#include<string>
#include<fstream>
#define FILENAME "empFile.txt"
using namespace std;
class worker{
    public:
    virtual void showInfo()=0;
    virtual string getDeptName()=0;
    int m_id;
    string m_name;
    int m_dId;
};

class workerManage{
    public:
    int empNum;
    bool fileIsempty;
    worker**empArray;
    workerManage();
    void showMenu(){
        cout<<endl;
        cout<<"0、退出职工管理系统"<<endl;
        cout<<"1、增加职工"<<endl;
        cout<<"2、显示职工"<<endl;
        cout<<"3、删除职工"<<endl;
        cout<<"4、修改职工"<<endl;
        cout<<"5、查找职工"<<endl;
        cout<<"6、排序职工"<<endl;
        cout<<"7、清空文档"<<endl;
        cout<<endl;
    }
    ~workerManage();
    void add();
    void input();//无脑将此时数组中的内容写入文件
    void initEmp();
    void showEmp();
    void delEmp();
    int getNum(int n);
    void modEmp();
    int findEmp();
    void sortEmp();
    void clear();
};

class employee:public worker{
    public:
    employee(int id,string name,int did){
        m_id=id;
        m_name=name;
        m_dId=did;
    }
    void showInfo(){
        cout<<"职工编号： "<<m_id<<endl;
        cout<<"职工姓名： "<<m_name<<endl;
        cout<<"职工职位： "<<this->getDeptName()<<endl;
        cout<<"职工职责：完成经理下发的任务"<<endl;
        cout<<endl;
    }
    string getDeptName(){
        return string("普通员工");
    }
};

class manager:public worker{
    public:
    manager(int id,string name,int did){
        m_id=id;
        m_name=name;
        m_dId=did;
    }
    void showInfo(){
        cout<<"职工编号： "<<m_id<<endl;
        cout<<"职工姓名： "<<m_name<<endl;
        cout<<"职工职位： "<<this->getDeptName()<<endl;
        cout<<"职工职责：完成老板下发的任务，并下发给普通员工"<<endl;
        cout<<endl;
    }
    string getDeptName(){
        return string("经理");
    }
};

class boss:public worker{
    public:
    boss(int id,string name,int did){
        m_id=id;
        m_name=name;
        m_dId=did;
    }
    void showInfo(){
        cout<<"职工编号： "<<m_id<<endl;
        cout<<"职工姓名： "<<m_name<<endl;
        cout<<"职工职位： "<<this->getDeptName()<<endl;
        cout<<"职工职责：管理公司事务"<<endl;
        cout<<endl;
    }
    string getDeptName(){
        return string("总裁");
    }
};

void workerManage::input(){
    ofstream ofs;
    ofs.open(FILENAME,ios::out);
    for(int i=0;i<empNum;i++){
        ofs<<empArray[i]->m_id<<" "
        <<empArray[i]->m_name<<" "
        <<empArray[i]->m_dId<<endl;
    }
    ofs.close();
}

void workerManage::add(){
    worker * wk=NULL;
    int addNum=0;
    cout<<"请输入要添加职工的个数：";
    cin>>addNum;
    int newSize=addNum+empNum;
    worker ** newSpace=new worker *[newSize]; 
    if(empArray!=NULL){
        for(int i=0;i<empNum;i++){
            newSpace[i]=empArray[i];
        }
    }
    for(int i=0;i<addNum;i++){
        int id;
        string name;
        int dId;
        cout<<"请输入第"<<i+1<<"个职工的编号： "<<endl;
        cin>>id;
        cout<<"请输入第"<<i+1<<"个职工的姓名： "<<endl;
        cin>>name;
        cout<<"请选择该职工的岗位"<<endl;
        cout<<"1、普通职工"<<endl;
        cout<<"2、经理"<<endl;
        cout<<"3、总裁"<<endl;
        cin>>dId;
        switch(dId){
            case 1:wk=new employee(id,name,1);
                break;
            case 2:wk=new manager(id,name,2);
                break;
            case 3:wk=new boss(id,name,3);
                break;
        }
        newSpace[i+empNum]=wk;
    }
    delete[] empArray;
    empArray=newSpace;
    empNum=newSize;
    cout<<"成功添加"<<addNum<<"名职工！"<<endl;
    this->input();
    system("clear");
}

workerManage::workerManage(){
    empNum=0;
    empArray=NULL;
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if(!ifs.is_open()){
        cout<<"文件未创建"<<endl;
        empNum=0;
        fileIsempty=true;
        empArray=NULL;
        ifs.close();
    }
    //集中情况分成几个函数来完成，不然会出现文件没有创建时却不识别不输出“文件未创建”
    ifs.open(FILENAME,ios::in);
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        cout<<"文件为空！"  <<endl;
        empNum=0;
        fileIsempty=true;
        empArray=NULL;
    }
    ifs.close();//分割------------------------------
    ifs.open(FILENAME,ios::in);
    int index=0;
    int id;
    string name;
    int dId;
    while(ifs>>id&&ifs>>name&&ifs>>dId){
        index++;
    }
    ifs.close();
    ifs.open(FILENAME,ios::in);
    empArray=new worker* [index];
    empNum=index;
    fileIsempty=false;
    int i=0;
    worker*wk;//建立一个作为数组成员出现的指针作为工具，每次读取到一个职工时帮助初始化
    while(ifs>>id&&ifs>>name&&ifs>>dId){
        if(dId==1){
            wk=new employee(id,name,1);
        }
        else if(dId==2){
            wk=new manager(id,name,2);
        }
        else{
            wk=new boss(id,name,3);
        }
        //因为目前empArray中的指针尚未创建且子类类型未知，所以首先创建指针而非用指针传入数据，如下
        // empArray[i]->m_id=id;
        // empArray[i]->m_name=name;
        // empArray[i]->m_dId=dId;
        empArray[i]=wk;//利用工具传入数据
        cout<<empArray[0]->m_name;
        i++;
    }
    ifs.close();
}

int workerManage::getNum(int n){
    if(this->fileIsempty){
        cout<<"文件不存在或记录为空！"<<endl;
    }
    else{
        for(int i=0;i<empNum;i++){
            if(n==empArray[i]->m_id){
                return i;
            }
            else{
                return -1;
            }
        }
    }
}

void workerManage::delEmp(){
    int n,a;
    cout<<"请输入要删除的职工的编号"<<endl;
    cin>>n;
    a=getNum(n);
    if(a==-1) cout<<"查无此人！"<<endl;
    else{
        for(int i=a;i<empNum;i++){
            empArray[i]=empArray[i+1];
        }
        empNum--;//一定要先更新数组数字才能做写入操作！
        this->input();
        cout<<"删除成功！"<<endl;
    }
}

void workerManage::showEmp(){
    if(fileIsempty){
        cout<<"文件不存在或记录为空"<<endl;
    }
    else{
        for(int i=0;i<empNum;i++){
            empArray[i]->showInfo();
        }
    }
}

workerManage::~workerManage(){
    if(empArray!=NULL){
        delete[] empArray;
        empArray=NULL;
    }
}

void workerManage::modEmp(){
    if(this->fileIsempty){
        cout<<"文件不存在或记录为空！"<<endl;
    }
    else{
        cout<<"请输入要修改的方式："<<endl;
        cout<<"1、按职工编号修改"<<endl;
        cout<<"2、按职工姓名修改"<<endl;
        int a,ret=-1;
        cin>>a;
        if(a==1){
            int n;
            cout<<"请输入要修改的职工编号："<<endl;
            cin>>n;
            for(int i=0;i<empNum;i++){
                if(n==empArray[i]->m_id){
                    ret=i;
                }
            }
        }
        if(a==2){
            cout<<"请输入要修改职工的编号"<<endl;
            string name;
            cin>>name;
            for(int i=0;i<empNum;i++){
                if(name==empArray[i]->m_name){
                    ret=i;
                }
            }
        }
        if(ret!=-1){
            cout<<"找到名为"<<empArray[ret]->m_name<<"的员工"<<endl;
            cout<<"请输入要修改的编号："<<endl;
            int id;
            string name;
            int dId;
            cin>>id;
            empArray[ret]->m_id=id;
            cout<<"请输入姓名："<<endl;
            cin>>name;
            empArray[ret]->m_name=name;
            cout<<"请输入职位："<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、总裁"<<endl;
            cin>>dId;
            empArray[ret]->m_dId=dId;
            cout<<"修改成功！"<<endl;
            this->input();
        }
        else{
            cout<<"输入有误！"<<endl;
        }
    }
}

int workerManage::findEmp(){
    cout<<"请输入要查找的方式："<<endl;
    cout<<"1、按职工编号查找"<<endl;
    cout<<"2、按职工姓名查找"<<endl;
    int a;
    cin>>a;
    if(a==1){
        int n;
        cout<<"请输入要查找的职工编号："<<endl;
        cin>>n;
        for(int i=0;i<empNum;i++){
            if(n==empArray[i]->m_id){
                cout<<"找到编号为"<<n<<"的员工"<<endl;
                empArray[i]->showInfo();
            }
        }
    }
    if(a==2){
        cout<<"请输入要查找职工的姓名"<<endl;
        string name;
        cin>>name;
        for(int i=0;i<empNum;i++){
            if(name==empArray[i]->m_name){
                cout<<"找到姓名为"<<name<<"的员工"<<endl;
                empArray[i]->showInfo();
            }
        }
    }
}

void workerManage::sortEmp(){
    cout<<"请选择要排序的方式："<<endl;
    cout<<"1、升序排列"<<endl;
    cout<<"2、降序排列"<<endl;
    int a;
    bool flag=false;
    cin>>a;
    for(int i=0;i<empNum;i++){
        int com=i;
        for(int j=i+1;j<empNum;j++){
            if(a==1){
                if(empArray[j]->m_id<empArray[com]->m_id){
                    com=j;
                }
            }
            if(a==2){
                if(empArray[j]->m_id>empArray[com]->m_id){
                    com=j;
                }
            }
        }
        if(i!=com){
            worker* temp=empArray[i];
            empArray[i]=empArray[com];
            empArray[com]=temp;
        }
    }
    cout<<"排序成功！"<<endl;
    this->input();
}

void workerManage::clear()
{
    cout<<"是否确认清空？"<<endl;
    cout<<"1、清空"<<endl;
    cout<<"2、返回"<<endl;
    int n;
    cin>>n;
    if(n==1)
    {
        ofstream ofs;
        ofs.open(FILENAME,ios::trunc);
        ofs.close();
        if(empArray!=NULL)
        {
            for(int i=0;i<empNum;i++)
            {
                if(empArray[i]!=NULL)
                {
                    empArray[i]=NULL;
                }
            }
            delete[] empArray;
            empNum=0;
            fileIsempty=true;
        }
        cout<<"清空成功！"<<endl;
    }
}

int main(){
    workerManage wm;
    while(1){
        wm.showMenu();
        int n;
        cin>>n;
        switch(n){
            case 0:cout<<"欢迎下次使用"<<endl;
                exit(0);//退出系统
                break;
            case 1:wm.add();//增加职工
                break;
            case 2:wm.showEmp();//显示职工
                break;
            case 3:wm.delEmp();//删除职工
                break;
            case 4:wm.modEmp();//修改职工
                break;
            case 5:wm.findEmp();//查找职工
                break;
            case 6:wm.sortEmp();//排序职工
                break;
            case 7:wm.clear();//清空文档
                break;
        }
    }
}