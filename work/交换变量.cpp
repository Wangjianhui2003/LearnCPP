#include <iostream>
using namespace std;
void swap(int &A,int &B)
{
    int C=A;
    A=B;
    B=C;
}
int main()
{
    int A;int B;
    cin>>A;
    cin>>B;
    swap(A,B);
    cout<<A<<B;
    return 0;
}