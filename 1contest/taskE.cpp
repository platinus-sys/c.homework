#include <iomanip>
#include <iostream>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  std::vector<long long> b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::vector<long long> c(n);
  for (int i = 0; i < n; i++) {
    c[i] = b[i] - a[i];
  }
  int q;
  std::cin >> q;
  std::vector<int> ans(q);
  for (int i = 0; i < q; i++) {
    int l = 0;
    int r = n - 1;
    int x;
    std::cin >> x;
    if (c[n - 1] >= x) {
      ans[i] = n;
    }
    while (r - l > 1) {
      if (c[(r + l) / 2] > x) {
        l = (r + l) / 2;
      } else {
        r = (r + l) / 2;
      }
    }
    if (b[l] < a[r] + x) {
      ans[i] = l + 1;
    } else {
      ans[i] = r + 1;
    }
  }
  for (auto x : ans) {
    std::cout << x << '\n';
  }
}
