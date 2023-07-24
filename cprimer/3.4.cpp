//比较两字符串大小
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string strA,strB;
    getline(cin,strA);
    getline(cin,strB);
    if(strA==strB)
    {
        cout<<"same"<<endl;
    }
    else if(strA>strB) cout<<strA<<endl;
    else cout<<strB<<endl;
    return 0;
}