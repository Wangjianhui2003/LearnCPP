//去除标点符号
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string line;
    string final;
    getline(cin,line);
    for(auto c:line)
    {
        if(!ispunct(c))
        {
            final += c;
        }
    }
    cout<<final<<endl;
    return 0;
}