#include<iostream>
#include<forward_list>
#include<string>
using namespace std;
void Insert(forward_list<string> &list,string a,string b)
{
    for(auto iter = list.begin();iter != list.end();)
    {
        if(*iter == a)
        {
            iter = list.insert_after(iter,b);
        }
        else
        {
            iter++;
        }
    }
}
int main()
{
    forward_list<string> list = {"hello","nice"};
    Insert(list,"hello","hello");
    return 0;
}