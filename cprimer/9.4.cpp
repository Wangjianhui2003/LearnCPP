//编写函数，判断vector特定范围是否存在num
#include<vector>
#include<iostream>
#include<iterator>
using namespace std;
bool find(int num,vector<int>::iterator Begin,vector<int>::iterator End)
    {
    for(auto index = Begin;index != End;index++)
    {
        if(*index == num){
            return true;
        }
    } 
    return false;
    }
int main(){
    vector<int> dict = {1,2,3,4,5,6};
    if(find(3,dict.begin(),dict.end()))
    {
        cout<<"true"<<endl;       
    }
    return 0;

}