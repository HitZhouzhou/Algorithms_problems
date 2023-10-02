#include <iostream>
using namespace std;
double s;
int main() {
  cin >> s;
  int ans = 0;
  double len = 2;
  while (s > 0) {
    s -= len;
    len *= 0.98;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
