## STL体系结构基础介绍
### STL六大部件(Compononts)：
> 容器(Containers)  
> 分配器(Allocators)  
> 算法(A1gorithms)  
> 迭代器(Iterators)  
> 适配器(Adapters)  
> 仿函数(Functors) 作用像函数对象的操作  
泛型编程 容器与算法分开  
容器由分配器分配 迭代器类似于泛型指针  
Container/Iterator/Functor Adapters:可以对容器，迭代器等做转换

```cpp
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;
int main()
{
    int ia[6]={27,210,12,47,109,83};
    vector<int,allocator<int>> vi(ia,ia+6);
    cout << count_if(vi.begin(),vi.end(),notl(bind2nd(less<int>(),40))); //计算出范围内符合这个条件的东西有几个

    return 0;
}
```

STL容器的迭代器均为前闭后开区间

### range-based for statement(since C++11)
推荐这样写
```cpp
for(decl:coll)
{
    statement;
}
for(int i:{2,3,4,5,6})      //遍历
{
    std::cout<<i<<std::endl;
}
std::vector<double> vec;
...
for(auto elem : vec)
{
    std::cout<<elem<<std::endl;
}
for(auto& elem : vec)
{
    elem*=3;
}
```
### auto keyword(适度使用)
```cpp
list<string> c;
...
list<string>::iterator ite;
ite=::find(c.begin(),c.end(),target);
//可以转化成下面这种
list<string> c;
...
auto ite=::find(c.begin(),c.end().target)
```
## 容器-结构与分类
> Sequence Containers: Array,Vecetor,Deque,List,ForwardList  
> Associative Containers: Set/Multiset, Map/Multimap  
> Unordered Containers: Unordered Set/Multiset, Unordred Map/Multimap  

C++标准库用的是HashTable with Seperate Chaining 目前最好