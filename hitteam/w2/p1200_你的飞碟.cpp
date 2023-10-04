#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s, t;
    cin >> s >> t;
    long long a = 1, b = 1;
    for (int i = 0; i < s.length(); i++)
    {
        a *= (s[i] - 'A' + 1);
        a %= 47;
    }
    for (int i = 0; i < t.length(); i++)
    {
        b *= (t[i] - 'A' + 1);
        b %= 47;
    }
    if (a % 47 == b % 47)
    {
        puts("GO");
    }
    else
        puts("STAY");
    return 0;
}