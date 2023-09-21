#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10100;
int f[N];
int n, m;
struct op {
  int x, y, t;
} g[N * N];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    g[i].t = t, g[i].x = x, g[i].y = y;
    f[i] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j < i; j++) {
      if (abs(g[i].x - g[j].x) + abs(g[i].y - g[j].y) <= abs(g[i].t - g[j].t))
        f[i] = max(f[i], f[j] + 1);
    }
    ans = max(ans, f[i]);
  }
  for (int i = 1; i <= m; i++) {
    ans = max(ans, f[i]);
  }
  cout << ans << endl;
  return 0;
}
