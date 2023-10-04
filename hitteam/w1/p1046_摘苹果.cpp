#include <iostream>
using namespace std;
int a[11];
int main() {
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    cin >> a[i];
  }
  int h;
  cin >> h;
  for (int i = 0; i < 10; i++) {
    if (h + 30 >= a[i]) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
