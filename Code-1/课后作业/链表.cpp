#include<iostream>
using namespace std;

struct Book{
    int value;
    struct Book *next;
};
static Book * tail=new Book;

void printBook(Book * library)
{
    Book * book=library;
    while(book!=NULL)
    {
        cout<<book->value<<" ";
        book = book->next;
    }
    cout<<endl;
}

void push_front(int value,Book ** library)//传入头指针
{
    Book *book=new Book;//上下消去一层指针等效
    book->value=value;//但那仅为值传递，两层指针就好像引用传递一样，要彻底修改指针的值
    if(*library!=NULL)
    {
        Book * temp=*library;//当library是头指针时
        *library=book;//*library为下一个链表的地址
        book->next=temp;
    }
    else
    {
        *library=book;
        book->next=NULL;
        tail=book;//必须加上这句话尾插才有效，因为必须初始化tail，否则必须先尾插tail才有效
    }
}

void push_back(int value,Book ** library)
{
    Book *book=new Book;
    book->value=value;//但那仅为值传递，两层指针就好像引用传递一样，要彻底修改指针的值
    if(*library!=NULL)
    {
        tail->next=book;
        book->next=NULL;
    }
    else
    {
        *library=book;
        book->next=NULL;
    }
    tail=book;
}
Book * search(int value,Book*library)
{
    Book * book=library;
    int x=0;
    while(book != NULL)
    {
        if(book->value==value)
        {
            x++;
            return book;
            continue;
        }
        book=book->next;
    }
    if(x==0) {
        cout<<"未找到"<<endl;
        return NULL;
    }
}

void clear_front(Book ** library)//头删接口
{
    if(*library!=NULL)
    {
        Book *temp=*library;
        *library=(*library)->next;
        free(temp);
    }
}

void clear_back(Book *tail);//寄，好像没法尾删
void printList(Book * library)
{
    Book * book =library;
    while(book!=NULL)
    {
        cout<<book->value<<" "<<endl;
        book=book->next;
    }
}

int main(){
    Book * library=NULL;
    // push_front(1,&library);
    // push_front(2,&library);
    // push_front(3,&library);
    // push_front(4,&library);
    // clear_front(&library);
    // push_back(5,&library);
    // push_front(5,&library);
    // search(5,library);
    // printBook(library);
    
    while(1){
        cout<<"已成功创建链表"<<endl;
        cout<<"1、头插"<<endl;
        cout<<"2、尾插"<<endl;
        cout<<"3、头删"<<endl;
        cout<<"4、查找"<<endl;
        cout<<"5、打印"<<endl;
        cout<<"6、退出"<<endl;
        int n;
        cin>>n;
        switch(n){
            case(1):
            {
                cout<<"请输入要添加的数字"<<endl;
                int a;
                cin>>a;
                push_front(a,&library);
                cout<<" 添加成功!"<<endl;
                break;
            }
            case(2):
            {
                cout<<"请输入要添加的数字"<<endl;
                int a;
                cin>>a;
                push_back(a,&library);
                cout<<" 添加成功!"<<endl;
                break;
            }
            case(3):
            {
                clear_front(&library);
                cout<<"删除成功！"<<endl;
                break;
            }
            case(4):
            {
                cout<<"请输入要查找的数字"<<endl;
                int a;
                cin>>a;
                Book * temp=search(a,library);
                if(temp==NULL)
                {
                    cout<<"未找到"<<endl;
                }
                else
                {
                    cout<<temp->value<<endl;
                }
                break;
            }
            case(5):printList(library);break;
            case(6):exit(0);
        }
    }
}