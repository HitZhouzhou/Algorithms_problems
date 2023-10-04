#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
string a;
void outre(int l, int r, bool sp)
{
    int i = l;
    int tr = r;
    while (l < r)
    {
        swap(a[l], a[r]);
        l++, r--;
    }
    while (a[i] == '0')
        i++;
    if (sp)
    {
        bool flag = false;
        while(a[tr]=='0')
        tr--;
        for (; i <= tr ; i++)
        {
            flag = true;
            cout << a[i];
        }
        if (!flag)
            cout << 0;
    }
    else
    {
        bool flag = false;
        for (; i <= tr; i++)
        {
            flag = true;
            cout << a[i];
        }
        if (!flag)
            cout << 0;
    }
}
int main()
{
    cin >> a;
    int l = 0, r;
    for (int i = 0; i < a.length(); i++)
    {
        char x = a[i];
        if (x == '.' || x == '/')
        {
            r = i - 1;
            outre(l, r, 0);
            cout << x;
            if (x == '.')
                outre(r + 2, a.length() - 1, 1);
            else
                outre(r + 2, a.length() - 1, 0);
            return 0;
        }
        if (x == '%')
        {
            r = i - 1;
            outre(l, r, 0);
            cout << x;
            return 0;
        }
    }
    outre(l, a.length() - 1, 0);
    return 0;
}