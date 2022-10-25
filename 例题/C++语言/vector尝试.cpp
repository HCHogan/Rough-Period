#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
int main()
{
	v.push_back(1);         //push_back用来在vector后面添加一个元素
	v.push_back(2);         //v.begin()起点的（地址）？
	v.push_back(3);         //v.erase(it)删除迭代器it处的元素 erase(first,last)删除[first,last)内的元素
	v.push_back(4);         //v.insert(it,x)用来在it处插入一个元素 时间复杂度为n
	v.push_back(5);         //clear用来清空vector内所有元素 时间复杂度为n
	v.push_back(6);         //pop_back()删除尾元素
	cout<<v.size()<<endl;
	v.erase(v.begin()+3);   //v.erase()删除一个元素 里面放地址 
	cout<<v.size()<<endl;   //v.size()长度
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";   
	}
	cout<<endl;
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
	    cout << (*it) << " ";  //用迭代器也行 类似于指针
	}   
	return 0;
}
