#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e5 + 100;
int a[N], map[N];
struct B {
  int x;
  bool operator<(const B &tb) { return map[x] < map[tb.x]; }
} b[N], q[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    map[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i].x;
  }
  int len = 0;
  for (int i = 1; i <= n; i++) {
    int l = 0, r = len;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      if (q[mid] < b[i])
        l = mid;
      else
        r = mid - 1;
    }
    len = max(len, r + 1);
    q[r + 1] = b[i];
  }
  cout << len << endl;
  return 0;
}
