#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10000;
int f[N][N];
char s[N], t[N];
int main() {
  cin >> (s + 1) >> (t + 1);
  int la = strlen(s + 1);
  int lb = strlen(t + 1);
  for (int i = 1; i <= la; i++) {
    f[i][0] = i;
  }
  for (int j = 1; j <= lb; j++) {
    f[0][j] = j;
  }
  for (int i = 1; i <= la; i++) {
    for (int j = 1; j <= lb; j++) {
      f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j] + 1);
      if (s[i] == t[j]) {
        f[i][j] = min(f[i][j], f[i - 1][j - 1]);
      }
      f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
    }
  }
  cout << f[la][lb];
  return 0;
}
