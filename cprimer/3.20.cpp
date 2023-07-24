//3.17的迭代器实现
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    vector<string> list;
    string word;
    while(cin>>word)
    {
        list.push_back(word);
    }
    for(auto a=list.begin();a!=list.end();a++)
    {
        for(auto &b:*a)
        {
            b=toupper(b);
        }
    }
    for(auto a : list)
    {
        cout<<a<<endl;
    }
    return 0;
}