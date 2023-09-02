#include <iostream>
#include <cstring>
using namespace std;

char a[500];
int main()
{
    cin >> a;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] != 'a' && a[i] != 'o' && a[i] != 'u' && a[i] != 'i' && a[i] != 'e')
        {
            cout << a[i];
        }
    }
    return 0;
}