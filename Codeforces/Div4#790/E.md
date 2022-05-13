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
