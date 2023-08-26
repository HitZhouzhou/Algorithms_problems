#include <iostream>
using namespace std;

int main()
{
    int n, m, s, p;
    cin >> n >> m >> s >> p;
    int min, sec;
    sec = n * m * 60 + n * s + p * (n - 1);
    min = sec / 60;
    sec %= 60;
    cout << min << endl
         << sec << endl;
    return 0;
}