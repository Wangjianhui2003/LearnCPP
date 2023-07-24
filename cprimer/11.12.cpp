//输入string和int存储到pair并添加到vector
#include<utility>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    vector<pair<string,int>> avector;
    string str;
    int i;
    while(cin>>str>>i)
        avector.push_back({str,i});
    for(const auto &p : avector)
        cout<<p.first<<":"<<p.second<<endl;
}