#include <iostream>
using namespace std;
int p[11], st[11];
void dfs(int u) {
  if (u == 10) {
    int s1 = 0, s2 = 0, s3 = 0;
    for (int i = 1; i <= 3; i++) {
      s1 = s1 * 10 + p[i];
    }
    for (int i = 4; i <= 6; i++) {
      s2 = s2 * 10 + p[i];
    }
    for (int i = 7; i <= 9; i++) {
      s3 = s3 * 10 + p[i];
    }
    if (s1 * 2 == s2 && s2 * 3 == s3 * 2) {
      printf("%d %d %d\n", s1, s2, s3);
    }
  }
  for (int i = 1; i <= 9; i++) {
    if (!st[i]) {
      p[u] = i;
      st[i] = 1;
      dfs(u + 1);
      st[i] = 0;
    }
  }
}
int main() {
  dfs(1);
  return 0;
}
