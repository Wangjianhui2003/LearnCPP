#include<iostream>
#include<time.h>
using namespace std;
int main()
{
    clock_t t=clock();
    int a=0;
    for(int i=1;i<2000000000;i++)
    {
        a+=i*(i+1)/2;
    }
    t = clock() -t;
    cout<<(float)t/CLOCKS_PER_SEC<<endl;
    return 0;
}//王建辉