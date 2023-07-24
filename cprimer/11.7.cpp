//用map实现向map中添加家族姓氏和孩子姓名
#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main()
{
    map<string,vector<string>> m;
    for(string fname;cout<<"family name?\n",cin>>fname && fname != "q";)
        for(string child;cout<<"children's name:\n",cin>>child &&child != "q";)
            m[fname].push_back(child);
} 