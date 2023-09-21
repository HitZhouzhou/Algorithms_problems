#include <iostream>
using namespace std;
const int N = 6 * 1e5 + 10;
int n, ans[N][12], cnt, a[N];
void dfs(int site, int num) {
  if (site > 10) {
    if (num == n) {
      cnt++;
      for (int i = 1; i <= 10; i++) {
        ans[cnt][i] = a[i];
      }
    }
    return;
  }
  for (int i = 1; i <= 3; i++) {
    if (i + num > n)
      break;
    a[site] = i;
    dfs(site + 1, num + i);
    a[site] = 0;
  }
}
int main() {
  cin >> n;
  dfs(1, 0);
  printf("%d\n", cnt);
  for (int i = 1; i <= cnt; i++) {
    for (int j = 1; j <= 10; j++) {
      cout << ans[i][j] << ' ';
    }
    puts("");
  }
  return 0;
}
