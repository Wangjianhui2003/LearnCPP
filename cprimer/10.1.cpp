//count函数
#include<algorithm>
using namespace std;
#include<string>
#include<vector>
#include<iostream>
int main()
{
    vector<int> avector({1,2,2,2,1,3,4,5,6,7});
    cout<<count(avector.begin(),avector.end(),2)<<endl;
    cout<<string(" ")<<endl;

}