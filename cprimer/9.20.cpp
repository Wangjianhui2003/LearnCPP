#include<deque>
#include<list>
using namespace std;
int main()
{
    list<int> L ={1,2,3,4,5,6,7,8,9};
    deque<int> odd,even;
    for(auto elem : L)
    {
        (elem%2 == 0 ? even : odd).push_back(elem);
    }

}