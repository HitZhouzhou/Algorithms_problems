#include <algorithm>
#include <iostream>
using namespace std;
const int N = 110;
int a[N], n, ans;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 3; i <= n; i++) {
    int x = a[i];
    bool flag = false;
    int l = 1, r = i - 1;
    while (l < r) {
      if (a[l] + a[r] < x) {
        l++;
      } else if (a[l] + a[r] > x) {
        r--;
      } else {
        flag = true;
        break;
      }
    }
    if (flag)
      ans++;
  }
  cout << ans << endl;
  return 0;
}
