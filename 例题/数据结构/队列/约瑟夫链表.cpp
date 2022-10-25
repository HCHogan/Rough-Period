#include<iostream>
using namespace std;

typedef struct SNode
{
    int data;
    SNode *next;
}SLNode;

main()
{
    int ListJoseph(int n,int m);
    int n,m;
    cout<<"n=";
    cin>>n;
    cout<<"m=";
    cin>>m;
    ListJoseph(n,m);
    return 0;
}

int ListJoseph(int n,int m)
{
    SLNode head,*p,*q;
    head.data=1;  //head为头结点，其数据域存放第一个元素的值，而非数据域为空的头指针
    p=&head;
    int j=2;
    if(n<2)
    {
        cout<<"总人数过少"<<endl;
        return 0;
    }
    while(j<=n)
    {
        /*在链表末尾新增一个结点，并使新增结点的next指针指向头结点*/
        q=new SLNode;
        q->data=j;
        q->next=&head;
        p->next=q;
        p=q;
        j++;
    }
    
    p=&head;
    int key=1;
    while(n>1)
    {
        key++;
        if(key==m)
        {
            /*当key==m时，删除对应的结点(p->next)*/
            SLNode *temp;
            temp=p->next;
            delete temp;
            p->next=p->next->next;
            n--;
            key=1;
        }
        p=p->next;
    }
    cout<<p->data<<endl;
    return 1;
}