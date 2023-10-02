#include <iostream>
using namespace std;
int ans, le, flag;
int main() {
  for (int i = 1; i <= 12; i++) {
    int a;
    cin >> a;
    if (300 + le < a) {
      flag = true;
      ans = -i;
      break;
    } else {
      ans += ((300 + le - a) / 100) * 100;
      le = 300 + le - ((300 + le - a) / 100) * 100 - a;
    }
  }
  if (flag)
    cout << ans << endl;
  else
    cout << le + ans * 1.2 << endl;
  return 0;
}
