//将单词存入vector并全部转换成大写
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
    for(auto &elm:list)
    {
        for(auto &c:elm)
        {
            c=toupper(c);
        }
    }
    for(auto elm:list)
    {
        cout<<elm<<endl;
    }
    return 0;

}