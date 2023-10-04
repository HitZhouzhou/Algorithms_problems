#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e6 + 100;
long long a[N];
long long ans, n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long sum = 0;
  a[0] = -1000;
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      sum++;
      ans = max(ans, sum);
    } else {
      ans = max(ans, sum);
      sum = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
