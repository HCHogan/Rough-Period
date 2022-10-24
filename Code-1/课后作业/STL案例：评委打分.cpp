#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<ctime>
using namespace std;
class Person{
public:
    string m_name;
    int m_score;
    Person(string name,int score){
        m_name=name;
        m_score=score;
    }
};

int main(){
    srand((unsigned int)time (NULL));
    vector<Person>v;
    string str="ABCDE";
    for(int i=0;i<5;i++){
        string name="选手";
        name+=str[i];
        int score=0;
        Person p(name,score);
        v.push_back(p);
    }
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        deque<int>d;
        for(int i=0;i<10;i++)
        {
            int num=rand()%41+60;
            d.push_back(num);
        }
        sort(d.begin(),d.end());
        d.pop_back();
        d.pop_front();
        int sum=0;
        for(deque<int>::iterator id=d.begin();id!=d.end();id++)
        {
            sum+=(*id);
        }
        int ave=sum/(d.size());
        (*it).m_score=ave;
        cout<<(*it).m_name<<"  "<<(*it).m_score<<endl;
    }
}