#include<iostream>
#include<forward_list>
using namespace std;
int main()
{
    forward_list<int> list = {1,2,3,4,5,6,7,8,9};
    auto prev = list.before_begin();
    auto curr = list.begin();
    while(curr != list.end())
    {
        if(*curr % 2)
        {
            curr = list.erase_after(prev);
        }
        else{
            prev = curr;
            ++curr;
        }
    }
    for(auto iter : list)
    {
        cout<<iter<<endl;
    }

}