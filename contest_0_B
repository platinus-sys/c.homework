#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
int main() {
  int n;
  std::cin >> n;
  std::vector<long double> log_a(n);
  std::vector<long double> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    log_a[i] = logl(a[i]);
  }
  std::vector<long double> pref(n);
  pref[0] = log_a[0];
  for (int i = 1; i < n; i++) {
    pref[i] = pref[i - 1] + log_a[i];
  }
  int q;
  std::cin >> q;
  const int cT = 10;
  for (int i = 0; i < q; i++) {
    int l;
    int r;
    std::cin >> l >> r;
    if (l != 0) {
      std::cout << std::fixed << std::setprecision(cT)
                << exp((pref[r] - pref[l - 1]) / (r - l + 1)) << '\n';
    }
    if (l == 0) {
      std::cout << std::fixed << std::setprecision(cT) << exp(pref[r] / (r + 1))
                << '\n';
    }
  }
}
