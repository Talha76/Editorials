## A. Lucky
<details>
  <summary>Tutorial</summary>

  This problem is simple. Just do as the problem statement says.

</details>
<details>
  <summary>Solution</summary>

  ```cpp
  // author: Mushfiq_Talha

  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int T;cin>>T;for(int kase=1;kase<=T;kase++)

  using namespace std;

  void solve() {
      string s;
      cin >> s;
      if(s[0] + s[1] + s[2] == s[3] + s[4] + s[5])
          cout << "YES";
      else
          cout << "NO";
      cout << '\n';
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }

  ```

</details>

## B. Equal Candies
<details>
  <summary>Hint</summary>

  Find out the value to which all the values should be converted.

</details>
<details>
 <summary>Tutorial</summary>

 Since we cannot add candies to any boxes, we have to make the number of candies of all the boxes equal to the minimum number of candies in a box, i.e. total number of
  candies to eat is ![](https://latex.codecogs.com/svg.image?\sum_{i=5}^{n}(a_i-min(a))).
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int T;cin>>T;for(int kase=1;kase<=T;kase++)
  #define all(v) v.begin(), v.end()
  using namespace std;

  void solve() {
      int n;
      cin >> n;
      vector<int> a(n);
      for(auto &i: a)
          cin >> i;

      int Min = *min_element(all(a));
      int sum = 0;
      for(auto i: a)
          sum += i - Min;
      cout << sum << '\n';
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }
  ```

</details>

## C. Most Similar Words
<details>
  <summary>Hint</summary>

  Find total number of moves to make two characters equal.
</details>
<details>
  <summary>Tutorial</summary>

  The minimum number of moves to make two characters ![](https://latex.codecogs.com/svg.image?a) & ![](https://latex.codecogs.com/svg.image?b) equal is
  ![](https://latex.codecogs.com/svg.image?\left|a-b\right|). Now we can apply brute force on the array to compare each of the pair of the strings to get the minimum number of moves to make two strings equal in ![](https://latex.codecogs.com/svg.image?O(n^2)) time complexity. We can get the total number of moves to make two strings
  ![](https://latex.codecogs.com/svg.image?s) & ![](https://latex.codecogs.com/svg.image?t) equal by doing ![](https://latex.codecogs.com/svg.image?\sum_{i=1}^{m}\left|s_i-t_i\right|).
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  // author: Mushfiq_Talha

  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int T;cin>>T;for(int kase=1;kase<=T;kase++)

  using namespace std;

  int n, m;
  int f(string a, string b) {
      int t = 0;
      for(int i = 0; i < m; i++) {
          t += abs(a[i] - b[i]);
      }

      return t;
  }

  void solve() {
      cin >> n >> m;
      vector<string> s(n);
      for(auto &i: s)
          cin >> i;

      int Min = 2e9;
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
              if(i != j)
                  Min = min(Min, f(s[i], s[j]));
          }
      }

      cout << Min << '\n';
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }
  ```
</details>
  
## D. X-Sum
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
  
## E. Eating Queries
<details>
  <summary>Hint</summary>

  Think of a prefix sum approach.
</details>
<details>
  <summary>Tutorial</summary>

  At first, we solve this question with one query. For making the sum of sugars at least ![](https://latex.codecogs.com/svg.image?x), we can greedily choose the largest
  numbers till we get sum greater than or equal to ![](https://latex.codecogs.com/svg.image?x); this way, we will get the minimum amount of candies. We can do this by sorting at first and then, traversing through the arrays and summing up until we get value greater than or equal to ![](https://latex.codecogs.com/svg.image?x). But doing this for large queries will be costly. So we can use a prefix sum array of the sorted array, and then doing binary search, since the prefix sum array will be sorted.
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  // author: Mushfiq_Talha

  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int T;cin>>T;for(int kase=1;kase<=T;kase++)
  #define all(v) v.begin(), v.end()
  #define ulta(v) v.rbegin(), v.rend()

  using namespace std;

  void solve() {
      int n, q;
      cin >> n >> q;
      vector<int> a(n);
      for(auto &i: a)
          cin >> i;

      sort(ulta(a));
      partial_sum(all(a), a.begin());

      while(q--) {
          int x;
          cin >> x;
          int ans = lower_bound(all(a), x) - a.begin() + 1;
          cout << (ans > n ? -1 : ans) << '\n';
      }
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }
  ```
</details>

## F. Longest Strike
<details>
  <summary>Tutorial</summary>

  We have to sort the array and then separate the values which meet the condition <img src="https://latex.codecogs.com/svg.image?\bg{white}a_i\geq&space;k" title="https://latex.codecogs.com/svg.image?\bg{white}a_i\geq k" /> 
  . Then within the separated values iterate through the values till two adjacent elements are not consecutive. And then compare the `l` and `r` with the condition 
  given until the last element of the array.
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  /*
   * author: Mushfiq_Talha
   */
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
      int n, k;
      cin >> n >> k;
      map<int, int> cnt;
      for(int i = 0; i < n; i++) {
          int t;
          cin >> t;
          cnt[t]++;
      }

      vector<int> v;
      for(auto [a, b]: cnt)
          if(b < k)
              v.push_back(a);

      for(auto i: v)
          cnt.erase(i);

      v.clear();
      for(auto [a, b]: cnt)
          v.push_back(a);

      if(v.empty()) {
          cout << -1 << '\n';
          return;
      }

      int l = v.front(), r, Max = 0;
      PII ans;
      v.push_back(1e9 + 5);
      for(int i = 1; i < (int)v.size(); i++) {
          if(v[i] - v[i - 1] > 1) {
              r = v[i - 1];
              if(r - l >= Max) {
                  ans = {l, r};
                  Max = r - l;
              }
              l = v[i];
          }
      }

      cout << ans.first << ' ' << ans.second << '\n';
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }
  ```
</details>
