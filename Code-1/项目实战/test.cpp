#include<iostream>
using namespace std;
#include<fstream>
int main()
{
    ifstream ifs("speech.csv",ios::in);
    string data;
    while(ifs>>data)
    {
        cout<<data;
        cout<<endl;
    }
}