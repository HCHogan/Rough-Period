#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<ctime>
#include<algorithm>
#include<string>
#include<deque>
#include<numeric>
#include<fstream>
class Speaker{
public:
    string Name;
    double Score[2];
    // Speaker(string name)
    // {
    //     Name=name;
    // }
};

class speechManage{
public:
    void showInfo();
    //int num=0;
    speechManage();
    ~speechManage();
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    int index;
    bool fileIsEmpty;
    map<int,Speaker>m_Speaker;
    map<int,vector<string> >m_Record;
    void Exit();
    void initSpeech();
    void startSpeech();
    void createSpeaker();
    void draw();
    void process();
    void saveRecord();
    void showScore();
    void loadRecord();
    void showRecord();
    void clearRecord();
};


void speechManage::initSpeech()
{
    v1.clear();
    v2.clear();
    v3.clear();
    index=1;
    m_Speaker.clear();
    m_Record.clear();
}

void speechManage::createSpeaker()
{
    string nameSeed="ABCDEFGHJIKL";
    for(int i=0;i<12;i++)
    {
        Speaker sp;
        sp.Name="选手";
        sp.Name+=nameSeed[i];
        for(int i=0;i<2;i++)
        {
            sp.Score[i]=0;
        }
        int id=i+10001;
        m_Speaker.insert(make_pair(id,sp));
        v1.push_back(id);
    }
}

speechManage::speechManage()//---------------------------------------
{
    this->initSpeech();
    loadRecord();
}

speechManage::~speechManage()
{
    //
}

void speechManage::showInfo()
{
    cout<<"欢迎使用演讲比赛系统"<<endl;
    cout<<"1、开始演讲比赛"<<endl;
    cout<<"2、查看往届信息"<<endl;
    cout<<"3、清除往届信息"<<endl;
    cout<<"4、退出程序"<<endl;
}

void speechManage::startSpeech()//---------------
{
    //loadRecord();
    createSpeaker();
    draw();
    process();
    showScore();
    index++;
    //num=0;
    draw();
    process();
    showScore();
    saveRecord();
    //index=1;
    //num=0;
    initSpeech();
    //createSpeaker();
    loadRecord();
}

void speechManage::Exit(){
    cout<<"欢迎下次使用！"<<endl;
    exit(0);
}

void speechManage::draw()
{
    //cout<<"第"<<index<<"轮抽签结果如下： "<<endl;
    srand((unsigned)time(NULL));
    if(index==1){
        random_shuffle(v1.begin(),v1.end());
    }
    if(index==2){
        random_shuffle(v2.begin(),v2.end());
    }
    // for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    // {
    //     cout<<*it<<"  ";
    // }
}

void speechManage::process()
{
    vector<int>vx;
    if(index==1) {vx.resize(v1.size());vx=v1;}
    else {vx.resize(v2.size());vx=v2;}
    multimap<double,int,greater<double> >groupSpore;
    int num=0;
    for(vector<int>::iterator it=vx.begin();it!=vx.end();it++)
    {
        num++;
        //cout<<vx.size();
        deque<double>d;
        for(int i=0;i<10;i++)
        {
            int score=(rand()%401+600)/10.f;
            d.push_back(score);
        }
        sort(d.begin(),d.end(),greater<double>());
        d.pop_back();
        d.pop_front();
        double sum=accumulate(d.begin(),d.end(),0.0f);
        double avg=sum/(double)d.size();
        m_Speaker[*it].Score[index-1]=avg;
        groupSpore.insert(make_pair(avg,*it));
        d.clear();
        if(num%6==0)
        {
            cout<<"第"<<num/6<<"组的比赛情况如下"<<endl;
            for(multimap<double,int,greater<double> >::iterator id=groupSpore.begin();id!=groupSpore.end();id++)
            {
                cout<<"编号： "<<id->second<<"姓名： "<<m_Speaker[id->second].Name<<"分数： "<<id->first;
                cout<<endl;
            }
            //groupSpore.clear();
            int cnt=0;
            for(multimap<double,int,greater<double> >::iterator id=groupSpore.begin();id!=groupSpore.end()&&cnt<3;id++,cnt++)
            {
                if(index==1) v2.push_back(id->second);
                if(index==2) v3.push_back(id->second);
            }
            groupSpore.clear();
        }
    }
    //vx.clear();
}

void speechManage::showScore()
{
    cout<<"第"<<index<<"轮晋级选手如下： "<<endl;
    vector<int>v;
    if(index==1) {v=v2;}
    else {v=v3;}
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<"  姓名： "<<m_Speaker[*it].Name<<"  分数： "<<m_Speaker[*it].Score[index-1];
        cout<<endl;
    }
    v.clear();
}

void speechManage::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv",ios::out | ios::app);
    for(vector<int>::iterator it=v3.begin();it!=v3.end();it++)
    {
        ofs<<*it<<","<<m_Speaker[*it].Score[1]<<",";
    }
    ofs<<endl;//没有换行就只有一届的记录
    ofs.close();
    cout<<"记录保存成功！"<<endl;
    fileIsEmpty=false;
}

void speechManage::loadRecord()
{
    ifstream ifs("speech.csv",ios::in);
    if(!ifs.is_open()) {fileIsEmpty=true;;ifs.close();return;}
    char ch;
    ifs>>ch;
    if(ifs.eof()) {fileIsEmpty=true;ifs.close();return;}
    fileIsEmpty=false;
    ifs.putback(ch);
    string data;
    int Index=0;
    //vector<string>v;
    while(ifs>>data)//一读一整行
    {
        vector<string>v;//这他吗。。。我无语，？？？？？？
        int pos=-1;
        int start=0;
        while(1)
        {
            string temp;
            pos = data.find(",",start);
            if(pos==-1) {break;}
            temp=data.substr(start,pos-start);
            v.push_back(temp);//每读一行定义一个新的v放进去，保证了index可以++
            start=pos+1;
        }
        // for(vector<string>::iterator it=v.begin();it!=v.end();it++)
        // {
        //     cout<<*it<<" ";
        // }
        // cout<<endl;
        m_Record.insert(make_pair(Index+1,v));
        Index++;
        //v.clear();
    }
    //Index++;
    //v.clear();
    ifs.close();
    //v.clear();
}

void speechManage::showRecord()
{
    if(fileIsEmpty) {cout<<"文件不存在或记录为空！"<<endl;}
    else{
        for(int i=0;i<m_Record.size();i++)
        {
            cout<<"第"<<i+1<<"届获奖名单尾"<<endl;
            cout<<"冠军编号： "<<m_Record[i+1][0]<<"冠军成绩： "<<m_Record[i+1][1]<<endl;
            cout<<"亚军编号： "<<m_Record[i+1][2]<<"亚军成绩： "<<m_Record[i+1][3]<<endl;
            cout<<"季军编号： "<<m_Record[i+1][4]<<"季军成绩： "<<m_Record[i+1][5]<<endl;
            //cout<<m_Record.size();
        }
    }
}

void speechManage::clearRecord()
{
    int n;
    cout<<"是否确认清空？"<<endl;
    cout<<"1、确认"<<endl;
    cout<<"2、返回"<<endl;
    cin>>n;
    if(n==1)
    {
        ofstream ofs;
        ofs.open("speech.csv",ios::trunc);//删除并重新创建文件
        initSpeech();
        //loadRecord();
        fileIsEmpty=true;
        cout<<"清空成功！"<<endl;
    }
    else{
        return;
    }
}

int main(){
    int n;
    srand((unsigned)time(NULL));
    speechManage sm;
    while(1)
    {
        sm.showInfo();
        cin>>n;
        switch(n)
        {
            case(1):sm.startSpeech();
                break;
            case(2):sm.showRecord();
                break;
            case(3):sm.clearRecord();
                break;
            case(4):sm.Exit();
                break;
            default:
                break;
        }
    }
}