#include <iostream>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int h, m;
  h = c - a;
  m = d - b;
  if (m < 0) {
    m += 60;
    h -= 1;
  }
  cout << h << ' ' << m << endl;
  return 0;
}
