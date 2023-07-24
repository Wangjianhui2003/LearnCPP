#include<stdio.h>
#include<iostream>
#include<time.h>
#include<math.h>
using namespace std;

bool primel(long n)
{
    long i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
            return false;
    
    }
    return true;
}
void PrimeTime1(long n){
    clock_t t;
    long sum=0,i;
    t=clock();
    for(i=2;i<=n;i++){
        if (primel(i)){
            sum++;
        }
    }
    t=clock()-t;
    cout<<(float(t)/CLOCKS_PER_SEC)<<endl;
    
}
bool prime2(long n){
    long i;
    for (i=2;i<=(int)sqrt(n);i++){
        if(n%i==0)
            return false;
    
    }
    return true;
}
void PrimeTime2(long n)
{
    clock_t t;
    long sum =0,i;
    t= clock();
    for(i=2;i<=n;i++)
    {
        if(prime2(i))
            sum++;
    }
    t=clock()-t;
    cout<<(float)t/CLOCKS_PER_SEC;
}
int main()
{
    long n;
    cin>>n;
    PrimeTime1(n);
    PrimeTime2(n);
    return 0;

}//王建辉