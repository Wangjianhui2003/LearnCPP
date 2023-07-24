//类模板应用
#include<iostream>
using namespace std;
template<class numtyp>
class number
{
    public:
        number(numtyp x,numtyp y)
        {
            a=x,b=y;
        }
        numtyp plus();
    private:
        numtyp a;
        numtyp b;
};
template<class numtyp>
numtyp number<numtyp>::plus()//重点
{
    numtyp c=a+b;
    cout<<c<<endl;
    return 0;//要有返回语句
}
int main()
{   
    number<int> intnum(4,5);
    number<double> doublenum(4.53,4.24);
    doublenum.plus();
    intnum.plus();
    return 0;
}
