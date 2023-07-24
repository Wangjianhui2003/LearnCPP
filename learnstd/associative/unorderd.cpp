#include<map>
#include<cstring>
#include<unordered_set>
#include<vector>
#include<iostream>
#include<iterator>
using namespace std;
map<int,char> mymap;
int main()
{
    unordered_set<string>myset = {"dfs","sdfff","dfsfs"};
    unordered_set<string>::const_iterator itr = myset.find("green");
    if (itr != myset.end())
    {
        cout<<*itr<<endl;
        myset.insert("yellow");
        vector<string> vec = {"purple","pink"};
        myset.insert(vec.begin(),vec.end());

    }
    

}