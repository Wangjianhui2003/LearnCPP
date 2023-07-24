//将字符转化为X
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string line;
    getline(cin,line);
    for(auto &c:line)
    {
        c='X';
    }
    cout<<line<<endl;
    return 0;
}