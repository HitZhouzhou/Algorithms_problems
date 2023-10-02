#include <algorithm>
#include <bitset>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

const int N = 30010;

int n, m, idx;
int seq[N], h[N], e[N], ne[N], d[N];
bitset<N> f[N];
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }
void topsort() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (!d[i]) {
      q.push(i);
    }
  }
  int cnt = 0;
  while (q.size()) {
    int t = q.front();
    q.pop();
    seq[cnt++] = t;
    for (int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      if (--d[j] == 0) {
        q.push(j);
      }
    }
  }
}
int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    add(a, b);
    d[b]++;
  }
  topsort();
  for (int i = n - 1; i >= 0; i--) {
    int j = seq[i];
    f[j][j] = 1;
    for (int k = h[j]; ~k; k = ne[k]) {
      f[j] |= f[e[k]];
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << f[i].count() << endl;
  }
  return 0;
}
