## [A. Lucky](https://codeforces.com/contest/1676/problem/A)
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

## [B. Equal Candies](https://codeforces.com/contest/1676/problem/B)
<details>
  <summary>Hint</summary>

  Find out the value to which all the values should be converted.

</details>
<details>
 <summary>Tutorial</summary>

 Since we cannot add candies to any boxes, we have to make the number of candies of all the boxes equal to the minimum number of candies in a box, i.e. total number of
  candies to eat is $\sum (a_i-min(a))$.
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

## [C. Most Similar Words](https://codeforces.com/contest/1676/problem/C)
<details>
  <summary>Hint</summary>

  Find total number of moves to make two characters equal.
</details>
<details>
  <summary>Tutorial</summary>

  The minimum number of moves to make two characters $a$ & $b$ equal is
  $\left|a-b\right|$. Now we can apply brute force on the array to compare each of the pair of the strings to get the minimum number of moves to make two strings equal in $O(n^2)$ time complexity. We can get the total number of moves to make two strings
  $s$ & $t$ equal by doing $\sum \left|s_i-t_i\right|$.
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
  
## [D. X-Sum](https://codeforces.com/contest/1676/problem/D)
<details>
  <summary>Hint</summary>

  Brute force.
</details>
<details>
  <summary>Tutorial</summary>

  Just iterate over all of the cells and take sum at four diagonals of that cell and find the maximum of all sums at $O(max(n,m)\cdot n\cdot m)$.
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
  
## [E. Eating Queries](https://codeforces.com/contest/1676/problem/E)
<details>
  <summary>Hint</summary>

  Think of a prefix sum approach.
</details>
<details>
  <summary>Tutorial</summary>

  At first, we solve this question with one query. For making the sum of sugars at least $x$, we can greedily choose the largest
  numbers till we get sum greater than or equal to $x$; this way, we will get the minimum amount of candies. We can do this by sorting at first and then, traversing through the arrays and summing up until we get value greater than or equal to $x$. But doing this for large queries will be costly. So we can use a prefix sum array of the sorted array, and then doing binary search, since the prefix sum array will be sorted.
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

## [F. Longest Strike](https://codeforces.com/contest/1676/problem/F)
<details>
  <summary>Tutorial</summary>

  We have to sort the array and then separate the values which meet the condition $a_i\geq k$ 
  . Then within the separated values iterate through the values till two adjacent elements are not consecutive. And then compare the $l$ & $r$ with the condition 
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

## [G. White-Black Balanced Subtrees](https://codeforces.com/contest/1676/problem/G)

## [H1. Maximum Crossings (Easy Version)](https://codeforces.com/contest/1676/problem/H1)
<details>
  <summary>Hint</summary>

  Find a condition for which two wires cross each other.
</details>
<details>
  <summary>Tutorial</summary>

  Observing the statement we can find that, two wires cross if and only one of these two conditions meet:  
  $$i< j \textit{ and } a_i\geq a_j$$
  $$i>j \textit{ and } a_i\leq a_j$$
  But we need just one of the above conditions for counting crossings. Because if we count for both conditions then we get twice of the answer. So we just take one of the 
  conditions.

  So we can traverse for each of the $i$ checking how many $j$ meet the condition, which will take $O(n^2)$, and we will get the answer.
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  /*
   * author: Mushfiq_Talha
   */
  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int tst;cin>>tst;for(int kase=1;kase<=tst;kase++)
  #define range(v, n) v, v + n
  #define all(v) v.begin(), v.end()
  #define toN(v, n) v.begin(), v.begin() + n
  #define ulta(v) v.rbegin(), v.rend()

  using namespace std;

  typedef long long ll;
  typedef pair<int, int> PII;

  void solve() {
      int n;
      cin >> n;
      vector<int> a(n);
      for(auto &i: a)
          cin >> i;

      int cnt = 0;
      for(int i = 0; i < n; i++) {
          for(int j = 0; j < n; j++) {
              if(i < j && a[i] >= a[j]) {
                  cnt++;
              }
          }
      }

      cout << cnt << '\n';
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }
  ```
</details>

## [H2. Maximum Crossings (Hard Version)](https://codeforces.com/contest/1676/problem/H2)
<details>
  <summary>Tutorial</summary>

  For this problem, we can't use the $O(n^2)$ 
  as we've done in the previous solution. But we know that for each $i$ and $j$, $a_i\geq a_j$. 
  So, we can store the values, and for each $i$, $1\leq i\leq n$ 
  we can count the values which are less than $a_i$, 
  and then delete $a_i$ from the list. In cpp, 
  we have a data structure called ordered_set, using which we can find the number of values strictly less than $x$ in $O(logn)$ 
  complexity.
</details>
<details>
  <summary>Solution 1</summary>

  ```cpp
  /*
   * author: Mushfiq_Talha
   */
  #include "bits/stdc++.h"
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int tst;cin>>tst;for(int kase=1;kase<=tst;kase++)
  #define range(v, n) v, v + n
  #define all(v) v.begin(), v.end()
  #define toN(v, n) v.begin(), v.begin() + n
  #define ulta(v) v.rbegin(), v.rend()

  using namespace std;
  using namespace __gnu_pbds;

  typedef long long ll;
  typedef pair<int, int> PII;
  typedef tree<
      int,
      null_type,
      less_equal<int>,
      rb_tree_tag,
      tree_order_statistics_node_update> ordered_set;

  void solve() {
      int n;
      cin >> n;
      vector<int> a(n);
      ordered_set s;
      map<int, int> cnt;
      for(auto &i: a) {
          cin >> i;
          s.insert(i);
          cnt[i]++;
      }

      ll ans = 0;
      for(auto i: a) {
          cnt[i]--;
          ans += cnt[i] + s.order_of_key(i);
          s.erase(s.find_by_order(s.order_of_key(i)));
      }

      cout << ans << '\n';
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }
  ```
</details>
<details>
  <summary>Solution 2</summary>

  ```cpp
  /*
   * author: Mushfiq_Talha
   */
  #include "bits/stdc++.h"
  #include <ext/pb_ds/assoc_container.hpp>
  #include <ext/pb_ds/tree_policy.hpp>

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int tst;cin>>tst;for(int kase=1;kase<=tst;kase++)
  #define range(v, n) v, v + n
  #define all(v) v.begin(), v.end()
  #define toN(v, n) v.begin(), v.begin() + n
  #define ulta(v) v.rbegin(), v.rend()

  using namespace std;
  using namespace __gnu_pbds;

  typedef long long ll;
  typedef pair<int, int> PII;
  typedef tree<
      pair<int, int>,
      null_type,
      less<pair<int, int>>,
      rb_tree_tag,
      tree_order_statistics_node_update> ordered_set;

  void solve() {
      int n, t = 0;
      cin >> n;
      vector<int> a(n);
      ordered_set s;
      for(auto &i: a) {
          cin >> i;
          s.insert({i, t++});
      }

      t = 0;
      ll ans = 0;
      const int inf = 1e9 + 1;
      for(auto i: a) {
          ans += s.order_of_key({i, inf}) - 1;
          s.erase(s.find_by_order(s.order_of_key({i, t++})));
      }

      cout << ans << '\n';
  }

  int main() {
      fast;

      tests
          solve();

      return 0;
  }
  ```
</details>
