#include<set>
#include<iostream>
using namespace std;
//no duplicates
int main()
{
    set<int> myset;

    myset.insert(3);//.insert() return pair
    myset.insert(2);//automatically sort ,o(log(n)),vary fast
    
    set<int>::iterator it;
    
    it = myset.find(2);//O(log(n))
    
    cout<<*it<<endl;

}
//.erase(pointer or value)
//set and multiset's value can not be modified