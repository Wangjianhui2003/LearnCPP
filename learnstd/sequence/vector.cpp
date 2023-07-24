#include<iterator>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> vec;
    vec.push_back(8);
    vec.push_back(4);


    vector<int>::iterator start = vec.begin();
    vector<int>::iterator end = vec.end(); //in vector,vec.end() points to the area after the last element
    
    for(vector<int>::iterator test =start;test != end;test++)
    {
        cout<<*test<<" "; //迭代器是一个指针!!
    }
    cout<<endl<<*(vec.end());//unknown output
    cout<<endl<<*(--vec.end());//output 4

    sort(start,end);//in <algorithm>

    cout<<endl;
    for(vector<int>::iterator test = start;test != end;test++)
    {
        cout<<*test<<" "; 
    }


    //int *p = &vec[1];
    //vec[1]=7;
    //p[1] = 5;
    //cout<<endl<<*(p);

    return 0;
}
//vec.size();
//vec.empty();
//vector<int> vec2(vec);
//vec.clear();
//vec2.swap(vec);