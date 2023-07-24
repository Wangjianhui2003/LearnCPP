#include<map>
using namespace std;
map<int,char> mymap;
int main(){


mymap.insert(pair<int,char>(1,'a'));
mymap.insert(make_pair(2,'b'));

map<int,char>::iterator it;
it = mymap.find(2);
}