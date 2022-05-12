<details>
  <summary>Hint</summary>

  Find out the value to which all the values should be converted.

</details>
<details>
 <summary>Tutorial</summary>
 
 Since we cannot add candies to any boxes, we have to make the nubmer of candies of all the boxes equal to the minimum number of candies in a box, i.e. total number of
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
