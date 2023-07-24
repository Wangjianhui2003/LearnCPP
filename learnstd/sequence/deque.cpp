#include<deque>
#include<iostream>
using namespace std;
int main()
{
    deque<int> deq = {4,6,2};
    deq.push_back(4);
    deq.push_front(2);
    cout<<deq[1]<<endl;
}