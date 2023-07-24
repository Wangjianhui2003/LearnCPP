#include <iostream>
using namespace std;
int main()
{
  char c;                        // 表示输入的一个字符
  int n1 = 0, n2 = 0, n3 = 0;    // 分别表示字母、数字、其它字符
  while ((c = getchar()) != '#') // 使用getchar函数
      n3++;
    if (c >= 'a' && c <= 'z' || c >= 'a' && c <= 'z')
      n1++;
    else if (c >= '0' && c <= '9')
      n2++;
    else
  cout << "c_count=" << n1 << "  n_count=" << n2;
  cout << "  o_count=" << n3 << "\n";
}