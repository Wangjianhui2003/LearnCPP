#include <iostream>
using namespace std;

int main()
{
  int now_year = 2022;
  while (now_year <= 2122)
  {
    if ((now_year% 4 == 0 && now_year% 100 != 0) or (now_year% 400 == 0))
    {
      cout << now_year << endl;
    }
    now_year++;
  }
  return 0;
}