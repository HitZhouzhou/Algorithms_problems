#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 70;
int sum, length, n, sticks[N];
bool st[N];
bool dfs(int u, int cur, int start) {
  if (u * length == sum)
    return true;
  if (cur == length)
    return dfs(u + 1, 0, 0);
  for (int i = start; i < n; i++) {
    int l = sticks[i];
    if (st[i])
      continue;
    if (l + cur <= length) {
      st[i] = true;
      if (dfs(u, cur + l, i + 1))
        return true;
      st[i] = false;
      if (!cur)
        return false;
      if (cur + l == length)
        return false;
      int j = i;
      while (j < n && sticks[j] == l)
        j++;
      i = j - 1;
    }
  }
  return false;
}
int main() {
  while (cin >> n, n) {
    memset(st, false, sizeof st);
    sum = 0, length = 0;
    for (int i = 0; i < n; i++) {
      cin >> sticks[i];
      if (sticks[i] > 50) {
        st[i] = true;
        continue;
      }
      sum += sticks[i];
      length = max(length, sticks[i]);
    }
    sort(sticks, sticks + n);
    reverse(sticks, sticks + n);
    while (true) {
      if (sum % length == 0 && dfs(0, 0, 0)) {
        cout << length << endl;
        break;
      }
      length++;
    }
  }
  return 0;
}
