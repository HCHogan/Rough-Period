#include <iostream>
#include <vector>
using namespace std;
vector<int> t;
int main()
{
    int m, p, n;
    cin >> n >> p >> m;
    for (int i = 0; i < n; i++)
    {
        t.push_back(i + 1);
    }
    int index = p - 1;
    while (t.size() > 0)
    {
        index = (m - 1 + index) % n;
        cout << t[index];
        t.erase(t.begin() + index);
        n--;
    }
}
/* nmsl */