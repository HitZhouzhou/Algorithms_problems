#include <iostream>
#include <cstring>
using namespace std;
int cnt[30];
int main()
{
    for (int i = 0; i < 4; i++)
    {
        string s;
        getline(cin,s);
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] >= 'A' && s[j] <= 'Z')
                cnt[s[j] - 'A']++;
        }
    }
    int m = 0;
    for (int i = 0; i <= 'Z' - 'A'; i++)
    {
        m = max(m, cnt[i]);
    }
    for (int i = m; i; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            if (cnt[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        puts("");
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        printf("%c ", i);
    }
    return 0;
}