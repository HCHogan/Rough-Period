#include<iostream>
using namespace std;
class CPU{
    public:
    virtual void calculate()=0;
};

class VideoCard{
    public:
    virtual void display()=0;
};

class storage{
    public:
    virtual void memory()=0;
};

class Computer{
    private:
        CPU* m_cpu;
        VideoCard* m_videoCard;
        storage* m_storage;
    public:
        Computer(CPU * cpu,VideoCard * vc,storage * storage){
            this->m_cpu=cpu;
            this->m_videoCard=vc;
            this->m_storage=storage;
        }
        void work(){
            m_cpu->calculate();
            m_videoCard->display();
            m_storage->memory();
        }
};

class IntelCPU:public CPU{
    public:
    virtual void calculate(){
        cout<<"英特尔CPU开始计算了!"<<endl;
    }
};

class IntelVideoCard:public VideoCard{
    public:
    virtual void display(){
        cout<<"英特尔显卡开始工作了!"<<endl;
    }
};

class IntelStorage:public storage{
    public:
    virtual void memory(){
        cout<<"英特尔内存条开始储存了！"<<endl;
    }
};

class AMDCPU:public CPU{
    public:
    virtual void calculate(){
        cout<<"AMDCPU开始计算了!"<<endl;
    }
};

class AMDVideoCard:public VideoCard{
    public:
    virtual void display(){
        cout<<"3080Ti显卡开始工作了!"<<endl;
    }
};

class SumsungStorage:public storage{
    public:
    virtual void memory(){
        cout<<"幻光戟内存条开始储存了！"<<endl;
    }
};

void test01(){
    CPU * cpu=new IntelCPU;
    VideoCard * vc=new IntelVideoCard;
    storage * mem=new IntelStorage;
    Computer* c=new Computer(cpu,vc,mem);
    c->work();
    delete c;
}
void test02(){
    CPU * cpu=new AMDCPU;
    VideoCard * vc=new AMDVideoCard;
    storage * mem=new SumsungStorage;
    Computer* c=new Computer(cpu,vc,mem);
    c->work();
    delete c;
}
int main(){
    test01();
    test02();
}