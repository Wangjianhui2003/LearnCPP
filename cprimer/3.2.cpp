//读入一行字符串并返回
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string line;
    while(getline(cin,line))
    {
        if(!line.empty()) 
        {
            cout<<line<<endl;
        }
    }
    return 0;
}
