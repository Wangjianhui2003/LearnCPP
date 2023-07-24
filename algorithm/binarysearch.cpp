#include<iostream>
using namespace std;
struct list{
    int data[20];
    int length = 20;
};
int search(list array,int item)
{
    int left,right,mid;
    left = 0;
    right = (array.length)-1;
    while(left<=right){
        mid = (left + right)/2;
        if(item>array.data[mid]) left = mid + 1;
        else if(item<array.data[mid]) right = mid - 1;
        else return mid;
    }
    return mid;
}


int main()
{
    list array;
    for(int i = 0;i<=19;++i)
    {
        array.data[i] = 3*i;
    }
    cout<<search(array,18)<<endl;
}