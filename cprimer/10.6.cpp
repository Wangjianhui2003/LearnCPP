//fill_n
#include<numeric>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<int> aVector({1,2,3,4,5});
    fill_n(aVector.begin(),5,0);
    for(auto a : aVector)
    {
        cout<<a<<endl;
    }
}