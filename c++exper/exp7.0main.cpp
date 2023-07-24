#include "exp7.0.cpp"
#include<iostream>
using namespace std;
int main()
{
    SqString s,s1,s2,s3,s4;
    StrAssign(s,"abcdefghijklmn");
    StrAssign(s1,"123");
    DispStr(s);
    printf("length of s:%d\n",StrLength(s));
    s2 = InsStr(s,9,s1);
    DispStr(s2);
    s2 = DelStr(s,2,3);
    DispStr(s2);
    s2 = RepStr(s,2,5,s1);
    DispStr(s2);
    s3 = SubStr(s,2,10);
    DispStr(s3);
    s4 = Concat(s1,s2);
    DispStr(s4);
    return 1;

}