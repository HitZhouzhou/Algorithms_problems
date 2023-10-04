#include <iostream>
using namespace std;
int main() {
  int k;
  cin >> k;
  double i = 1;
  double sum;
  while (true) {
    sum += 1 / i;
    if (sum > k) {
      break;
    }
    i++;
  }
  cout << i << endl;
  return 0;
}
