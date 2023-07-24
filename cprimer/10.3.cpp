//accumulate求和vector和
#include<numeric>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    vector<double> aVector({1,2,3,4,5,6,7});
    cout<<accumulate(aVector.cbegin(),aVector.cend(),0)<<endl;

}