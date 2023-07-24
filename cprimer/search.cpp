#include<iostream>
#include<string>
#include<vector>
using namespace std;
auto search(vector<int> list,int sought)
{
    auto beg = list.begin();
    auto end = list.end();
    auto mid = beg + (end - beg)/2;
    while(mid != end && *mid != sought)
    {
        if(sought<*mid)
        {
            end=mid;
        }
        else
        {
            beg = mid+1;
        }
        mid = beg + (end-beg)/2;
        
    }
    cout<<*mid;
    return 0;
}
int main()
{
    vector<int> list;
    for(int i = 0;i<100000;i++)
    {
        list.push_back(i);
    }
    search(list,12343);
}