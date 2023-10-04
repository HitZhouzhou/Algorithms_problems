#include <iostream>
using namespace std;
int n, a[110];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int sum = 0;
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i]) {
        sum++;
      }
    }
    printf("%d ", sum);
  }
  return 0;
}
