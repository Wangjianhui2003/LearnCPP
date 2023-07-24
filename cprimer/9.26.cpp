//删除vector，list中的奇数或偶数
#include<vector>
#include<list>
#include<iostream>
using namespace std;
int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    vector<int> even;
    list<int> odd;
    for(auto elem : ia)
    {
        even.push_back(elem);
        odd.push_back(elem);
    }
    for(auto iter = even.begin();iter != even.end();)
    {
        if(*iter % 2 == 0)
        {
            iter = even.erase(iter);
        }
        else{
            ++iter;
        }
    }
    for(auto iter = odd.begin();iter != odd.end();)
    {
        if(*iter % 2 != 0)
        {
            iter = odd.erase(iter);
        }
        else{
            ++iter;
        }
    }
    for(auto elem : odd)
    {
        cout<<elem<<endl;
    }
    for(auto elem : even)
    {
        cout<<elem<<endl;
    }
    return 0;
}