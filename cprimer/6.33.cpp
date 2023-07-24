//编写一个函数递归输出vector内容
#include<iostream>
#include<vector>
using namespace std;

using iter = vector<int>::const_iterator;

void outputvector(iter first,iter last){
    
    if(first != last){
        cout<<*first<<" ";
        outputvector(++first,last);
    }
    return;
}

int main()
{
	vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	outputvector(vec.cbegin(), vec.cend());
	return 0;
}