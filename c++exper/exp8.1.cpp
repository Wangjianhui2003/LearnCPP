//������_��Ч���x��n�η�
#include<stdio.h>
double expx(double x,int n)
{
    if( n == 1 )
        return x;
    else if(n%2 == 0)
        return expx(x,n/2) * expx(x,n/2);
    else
        return x * expx(x,(n-1)/2) * expx(x,(n-1)/2);
}

int main()
{
    double x;
    int n;
    printf("x:");scanf("%1f",&x);
    printf("n:");scanf("%d",&n);
    printf("%g��%d�η�:%g\n",x,n,expx(x,n));
    return 1;
}