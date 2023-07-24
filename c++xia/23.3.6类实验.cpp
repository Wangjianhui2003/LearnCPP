//类中静态变量，构造函数，默认构造函数，析构函数
#include<iostream>
using namespace std;
class stuff
{
    private:
        int hight,length,broadth;
        int v;
    public:
        static int classcount;
        int volume()
        {
            v=hight*length*broadth;
            return v;
        }
        stuff(int a=0,int b=0,int c=0):hight(a),length(b),broadth(c)
        {
            cout<<hight<<length<<broadth<<endl;
            classcount++;

        }
        ~stuff()
        {
            cout<<"stuff free!"<<endl;
        }


};

int stuff::classcount = 0;//类中静态数据必须要在类外初始化
int main()
{
    stuff cube(4,4,4);
    cout<<cube.volume()<<endl;
    stuff none;
    cout<<stuff::classcount<<endl;
    return 0;
}