#include <iostream>
using namespace std;
int main()
{
  long long x, n;
  cin >> x >> n;
  long long w, d;
  x = x - 1;
  w = n / 7;
  d = n - w * 7;
  int td = d;
  // 找从x到realday中是否有6,7;
  for (int i = 0; i < td; i++)
  {
    int realday = (x + i) % 7;
    if (realday == 6 || realday == 5)
      d--;
  }
  cout << 250 * (5 * w + d) << endl;
  return 0;
}
