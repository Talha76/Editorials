<details>
  <summary>Hint</summary>

  Brute force.
</details>
<details>
  <summary>Tutorial</summary>

  Just iterate over all of the cells and take sum at four diagonals of that cell and find the maximum of all sums at ![](https://latex.codecogs.com/svg.image?O(max(n,m)\cdot&space;n\cdot&space;m)).
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int T;cin>>T;for(int kase=1;kase<=T;kase++)
  #define range(v, n) v, v + n
  #define all(v) v.begin(), v.end()
  #define toN(v, n) v.begin(), v.begin() + n
  #define ulta(v) v.rbegin(), v.rend()

  using namespace std;

  typedef long long ll;
  typedef pair<int, int> PII;

  void solve() {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> a(n, vector<int>(m));
      for(auto &i: a) {
          for(auto &j: i)
              cin >> j;
      }

      vector<PII> dir{{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
      ll Max = 0;
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < m; j++) {
              ll sum = a[i][j];
              for(auto [k, l]: dir) {
                  int x = i + k, y = j + l;
                  while(x >= 0 && y >= 0 && x < n && y < m) {
                      sum += a[x][y];
                      x += k, y += l;
                  }
              }
              Max = max(Max, sum);
          }
      }

      cout << Max << '\n';
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }
  ```
</details>
