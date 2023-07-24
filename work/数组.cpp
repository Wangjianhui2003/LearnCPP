#include <iostream>
#include <string>
using namespace std;
int main()
{
    string students[] = {"1", "2", "3", "4", "5"};
    int number[] = {1111, 2222, 3333, 4444, 5555};
    string gender[] = {"woman", "man", "man", "woman", "man"};
    int age[] = {17, 18, 16, 18, 19};
    for (int i = 0; i <= 4; i++)
    {
        cout << students[i] << " " << number[i] << " " << gender[i] << " " << age[i] << endl;
    }
    return 0;
}