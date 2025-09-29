#include <iostream>
#include <string>
#include <vector>
int main() {
  std::string s;
  std::cin >> s;
  std::string t;
  std::cin >> t;
  int n = s.size();
  int m = t.size();
  std::vector<int> p(n);
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    a[p[i] - 1] = i;
  }
  int ans1 = 0;
  int ans2 = n;
  int ind1 = 0;
  int ind2 = 0;
  while (ind1 < n && ind2 < m) {
    while (ind1 < n && s[ind1] != t[ind2]) {
      ind1++;
    }
    ind2++;
  }
  if (ind2 < m) {
    std::cout << "error";
    return 0;
  }
  int ans = (ans1 + ans2) / 2;
  while (ans2 - ans1 > 1) {
    ans = (ans1 + ans2) / 2;
    ind2 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= ans && ind2 < m && s[i] == t[ind2]) {
        ind2++;
      }
    }
    if (ind2 == m) {
      ans1 = ans;
    } else {
      ans2 = ans;
    }
  }
  std::cout << ans1;
}
