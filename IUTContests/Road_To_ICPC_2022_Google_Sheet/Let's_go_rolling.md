## [Let's Go Rolling!](https://codeforces.com/problemset/problem/38/E)
<details>
  <summary>Tutorial</summary>

  This is a DP solution.
  We take the input as pairs, i.e. $pair\\{a, b\\} = \\{\textit{co-ordinate}, cost\\}$. Then we sort the array of pairs, since we need to traverse the array in increasing order.
  Now, for each index of co-ordinate, we have 2 options, either to stick a pin to it or let it roll to the previous stuck pin. We can do this with a naive recursion. But If we look closely, for every index and every stuck pin previous to this index, we will repeat the same recursive procedure, which we can store in $dp_{i,j}=\textrm{minimum cost for index i if j was pinned before}$. So, we apply this dp function to all $i,j,1\leq j< i \leq n$.
  <details>
    <summary>Base Case</summary>

    dp[n][i] = 0, for all i ( 0-base indexing )
  </details>
  <details>
    <summary>Transition</summary>

    dp[i][j] = min(arra[i].cost + f(i + 1, i), arra[i].x - arra[j].x + f(i + 1, j))
  </details>
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  // In the name of Allah, the Most Gracious, the Most Merciful
  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int t=1;if(multi_test)cin>>t;for(int kase=1;kase<=t;kase++)
  #define caseout cout << "Case " << kase << ": "
  #define range(v, n) v, v + n
  #define all(v) v.begin(), v.end()
  #define partial(v, n) v.begin(), v.begin() + n
  #define ulta(v) v.rbegin(), v.rend()
  #define precision(x) fixed << setprecision(x)
  #define watch(x) cout << #x << "=" << x
  #define x first
  #define c second

  using namespace std;

  typedef long long ll;
  typedef pair<int, int> PII;

  const bool multi_test = false;
  int n;
  vector<PII> a;
  vector<vector<ll>> dp;

  ll f(int i, int pre) {
    if(i == n)
      return 0;
    if(dp[i][pre] != -1)
      return dp[i][pre];

    ll ret = min(a[i].c + f(i + 1, i), a[i].x - a[pre].x + f(i + 1, pre));
    return dp[i][pre] = ret;
  }

  void magic() {
    cin >> n;
    a.resize(n), dp.assign(n + 1, vector<ll>(n + 1, -1));
    for(auto &[i, j]: a)
      cin >> i >> j;

    sort(all(a));

    cout << a[0].c + f(1, 0);
  }

  signed main() {
    fast;

    tests {
      magic();
      cout << '\n';
    }

    return 0;
  }
  ```
</details>