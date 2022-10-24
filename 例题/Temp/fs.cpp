#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> v;
int qsort(int L,int R)
{
  if(L>=R) return 0;
  int i=L-1,j=R+1;
  while(i<j)
  {
    int t=v[L];
    while(v[++i]<t);
    while(v[--j]>t);
    if(i<j) swap(v[i],v[j]);
  }
  qsort(L,j),qsort(j+1,R);
}
int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    v.push_back(x);
  }
  qsort(0,v.size()-1);
  for(int i=0;i<n;i++) cout<<v[i]<<" ";
  cout<<endl;
  return 0;
}