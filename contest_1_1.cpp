#include <iostream>
#include <vector>
void Sort(std::vector<std::pair<int, int>>& a) {
  int n = a.size();
  if (n <= 1) {
    return;
  }
  std::vector<std::pair<int, int>> b(n / 2);
  std::vector<std::pair<int, int>> c(n - n / 2);
  for (int i = 0; i < n; i++) {
    if (i < n / 2) {
      b[i] = a[i];
    } else {
      c[i - n / 2] = a[i];
    }
  }
  Sort(b);
  Sort(c);
  int ind1 = 0;
  int ind2 = 0;
  for (int i = 0; i < n; i++) {
    if (ind1 >= n / 2) {
      a[i] = c[ind2];
      ind2++;
      continue;
    }
    if (ind2 >= n - n / 2) {
      a[i] = b[ind1];
      ind1++;
      continue;
    }
    if (b[ind1].first < c[ind2].first) {
      a[i] = b[ind1];
      ind1++;
    } else if (b[ind1].first > c[ind2].first) {
      a[i] = c[ind2];
      ind2++;
    } else {
      if (b[ind1].second > c[ind2].second) {
        a[i] = b[ind1];
        ind1++;
      } else {
        a[i] = c[ind2];
        ind2++;
      }
    }
  }
}
int main() {
  int n{};
  std::cin >> n;
  std::vector<std::pair<int, int>> a(2 * n);
  for (int i = 0; i < n; i++) {
    int l;
    int r;
    std::cin >> l >> r;
    a[2 * i] = {l, 1};
    a[2 * i + 1] = {r, -1};
  }
  Sort(a);
  int ans1 = 0;
  std::vector<std::pair<int, int>> ans2;
  ans2.reserve(n);
  int flag = 1;
  int st = 0;
  for (int i = 1; i < 2 * n; i++) {
    if (flag == 0) {
      st = i;
    }
    flag += a[i].second;
    if (flag == 0) {
      ans1++;
      ans2.push_back({a[st].first, a[i].first});
    }
  }
  std::cout << ans1 << '\n';
  for (auto x : ans2) {
    std::cout << x.first << ' ' << x.second << '\n';
  }
}
