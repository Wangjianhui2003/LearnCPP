//使用initializer_list类型传入可变数量形参
#include<initializer_list>
#include<iostream>
using namespace std;

int sum(initializer_list<int> num){//输出数的总和
    int allnum = 0;
    for(auto number : num){
        allnum += number;
    }
    return allnum;
}


int main(){
    cout<<sum({1,2,3,4,5})
        <<endl
        <<sum({1,2,3,4,5,6,7,8,9});
}