//读入字符串并存入vector
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string line;
    vector<string> alist;
    while(getline(cin,line))
    {
        alist.push_back(line);
    }
    return 0;
}