#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int x, n;
  cin >> n >> x;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int ti = i;
    while (ti) {
      int a = ti % 10;
      ti /= 10;
      if (a == x)
        ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
