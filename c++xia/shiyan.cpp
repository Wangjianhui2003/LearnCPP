#include<iostream>
#include<cstring>
using namespace std;
class girl;
class afriend
{
	private:
		string name;
		int age;
		string hobby;
	public:
	   afriend(string name1="li",int age1=5,string hobby1="pp"):name(name1),age(age1),hobby(hobby1)	{}//怀疑未初始化
	   void display(girl &a)
	   {
	   	cout << a.name<<endl<<a.age<<a.character<<endl;
	   }
	   
	   ~afriend()
	   {cout <<"使用析构函数"<<endl;
	   }
		
};

class girl
{
    friend afriend;
	private:
		string name;
		int age;
		string character;
	public:
		girl(string name1="55",int age1=5,string c1="22"):name(name1),age(age1),character(c1){}
		//~girl;//析构函数不完整 会返回minvaild use of incomplete type class girl
		~girl()
		{
			cout <<"有使用析构函数"<<endl;
		}
};

int main()
{
	girl b("li binbin",19,"happy");
	afriend me;
	me.display(b);
	return 0;
}
