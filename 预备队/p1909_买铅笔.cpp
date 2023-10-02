#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 0x3f3f3f3f;
  for (int i = 1; i <= 3; i++) {
    int a, b, sum;
    cin >> a >> b;
    int num = 0;
    if (n % a == 0) {
      num = n / a;
    } else
      num = n / a + 1;
    sum = num * b;
    ans = min(ans, sum);
  }
  cout << ans;
  return 0;
}
