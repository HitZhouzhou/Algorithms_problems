#include <iostream>
#include <cstring>
using namespace std;
string a, b;
int main()
{
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = tolower(a[i]);
    }
    for (int i = 0; i < b.length(); i++)
    {
        b[i] = tolower(b[i]);
    }
    a = ' ' + a + ' ';
    b = ' ' + b + ' ';
    if (b.find(a) == string::npos)
    {
        cout << -1 << endl;
        return 0;
    }
    int alpha = b.find(a);
    int beta = b.find(a);
    int s = 0;
    while (beta != string::npos)
    {
        ++s;
        beta = b.find(a, beta + 1);
    }
    cout << s << ' ' << alpha << endl;
    return 0;
}