#include <algorithm>
#include <iostream>
using namespace std;
long long cnt = 0, a[110];
int main() {
  int x;
  cin >> x;
  while (x != 0) {
    a[cnt++] = x;
    cin >> x;
  }
  for (int i = cnt - 1; i >= 0; i--) {
    printf("%lld ", a[i]);
  }

  return 0;
}
