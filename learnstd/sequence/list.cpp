#include<algorithm>
#include<list>
#include<iostream>
using namespace std;
int main()
{
    list<int> alist= {5,3,8};
    alist.push_back(8);
    alist.push_front(6); //{6.5.3.8.8}

    list<int>::iterator pointer = find(alist.begin(),alist.end(),3); //pointer -> 3
    alist.insert(pointer,9); //{6,5,9,3,8,8}
    pointer++; //pointer -> 8
    alist.erase(pointer); //delete 8  list is a linkedlist container!!
    for(list<int>::iterator i=alist.begin();i!=alist.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    list<int> anotherlist={6,6,6,6};                                              //in <algorithm>
    alist.splice(--alist.end(),anotherlist,anotherlist.begin(),anotherlist.end());//splice from --alist.end
    for(list<int>::iterator i=alist.begin();i!=alist.end();i++)                    //very important
    {
        cout<<*i<<" ";
    }
    list<int>::iterator end = alist.end();
    cout<<endl<<*end;
    return 0;
}
//fast inster/remove at any place o(1)
//slow search
//no random access, no [] operater
//list is generally slower
