#include<iostream>
#include<cstring>
using namespace std;

class hehehe
{
    friend ostream& operator<< (ostream& cout,hehehe hehe);
public:
    hehehe()
    {
        m_ptr=NULL;
    }

    void alloc()
    {
        m_ptr=new int;
        memset(m_ptr,0,sizeof (int));
    }

    hehehe(hehehe&& hehe)       //如果用右值来初始化给this hehehe&&可以接收右值
    {                           //应为要吧hehe.m_ptr置空 所以不能加const
        if(&hehe==this) return; //如果接受的值是右值 但是找不到移动构造函数 就会去找拷贝构造函数
        if(this->m_ptr!=NULL)
        {
            delete m_ptr;
            m_ptr=NULL;
        }
        m_ptr=hehe.m_ptr;
        hehe.m_ptr=NULL;        //为啥要置空？
    }       //转移构造函数

    hehehe(hehehe& hehe)        //拷贝构造函数      这里可以加const
    {
        cout<<"屌用了拷贝构造函数"<<endl;
        alloc();
        this->m_ptr=new int(*hehe.m_ptr);
    }

    hehehe& operator=(hehehe& hehe)
    {
        cout<<"调用了拷贝赋值函数"<<endl;
        if(this==&hehe) return *this;
        if(m_ptr==NULL) alloc();
        memcpy(m_ptr,hehe.m_ptr,sizeof(int));
        return *this;
    }

    hehehe& operator=(hehehe&& hehe)
    {
        cout<<"调用了转移赋值函数"<<endl;
        if(m_ptr==NULL) alloc();
        m_ptr=hehe.m_ptr;
        hehe.m_ptr==NULL;       //为啥要置空？
        return *this;
    }

    //std::move()就是告诉编译器 虽然我是左值 但是对我使用移动构造函数 不要用拷贝构造函数
    //左值被转移以后 不会立即析构 而是离开自己作用域的时候才析构
    //因为已经被转移 如果再使用里面的值 就会寄
    //c++11所有容器都有移动语意

    ~hehehe()
    {
        if(m_ptr!=NULL)
        {
            delete m_ptr;
            m_ptr=NULL;
        }
    }
private:
    int* m_ptr;
};

ostream& operator<<(ostream& cout,hehehe hehe)
{
    cout<<"调用了重载<<输出了"<<*hehe.m_ptr<<endl;
    return cout;
}

