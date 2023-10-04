#include <iostream>
using namespace std;
int main() {
  int ans = 0, m = 0;
  for (int i = 1; i <= 7; i++) {
    int a, b;
    cin >> a >> b;
    if (a + b - 8 > m) {
      m = a + b - 8;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
