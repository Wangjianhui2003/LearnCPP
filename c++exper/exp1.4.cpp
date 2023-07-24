#include<iostream>
#include<stdio.h>
using namespace std;
long sum(int n)
{
    long sum = 0,fact = 1;
    for (int i = 1;i<=n;i++)
    {
        fact *= i;
        sum += fact;
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    if(n<3 || n>20) return 0;
    cout<<n<<sum(n);
    return 0;
}//王建辉