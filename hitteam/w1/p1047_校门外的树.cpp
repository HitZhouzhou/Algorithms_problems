#include <iostream>
const int N = 1e4 + 100;
int a[N];
using namespace std;
int main() {
  int l, m;
  cin >> l >> m;
  for (int i = 0; i <= l; i++)
    a[i] = 1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    for (int j = u; j <= v; j++) {
      a[j] = 0;
    }
  }
  int ans = 0;
  for (int i = 0; i <= l; i++)
    ans += a[i];
  cout << ans << endl;
  return 0;
}
