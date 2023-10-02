#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
int bxl, bxr, byl, byr;
int x1, x2, y1, y2;
typedef long long ll;
typedef pair<int, int> pii;
map<pii, bool> m;
map<pii, ll> d;
typedef long long ll;
ll bfs() {
  queue<pii> q;
  q.push({x1, y1});
  m[{x1, y1}] = true;
  while (!q.empty()) {
    auto t = q.front();
    q.pop();
    int tx = t.first, ty = t.second;
    int dx[] = {1, 1, -1 - 1, 2, 2, -2, -2},
        dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
    for (int i = 0; i < 8; i++) {
      int x = tx + dx[i], y = ty + dy[i];
      if (x >= bxl && x <= bxr && y >= byl && y <= byr && m[{x, y}] == false) {
        d[{x, y}] = d[{tx, ty}] + 1;
        if (x == x2 && y == y2)
          return d[{x, y}];
      }
    }
  }
  return -1;
}
int main() {
  cin >> x1 >> y1 >> x2 >> y2;
  bxl = min(x1, x2) - 2;
  bxr = max(x1, x2) + 2;
  byl = min(y1, y2) - 2;
  byr = max(y1, y2) + 2;
  cout << bfs();
  return 0;
}
