#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a[] = {4, 3, 2, 1};
    do
    {
        for (int i = 0; i < 4; i++)
        {
            cout << a[i] << ' ';
        }
        cout << endl;
    } while (prev_permutation(a, a + 4));
    return 0;
}