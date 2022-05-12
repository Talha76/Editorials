<details>
  <summary>Hint</summary>

  Find total number of moves to make two characters equal.
</details>
<details>
  <summary>Tutorial</summary>

  The minimum number of moves to make two characters ![](https://latex.codecogs.com/svg.image?a) & ![](https://latex.codecogs.com/svg.image?b) equal is 
  ![](https://latex.codecogs.com/svg.image?\left|a-b\right|). Now we can apply brute force on the array to compare each of the pair of the strings to get the minimum number of moves to make two strings equal in ![](https://latex.codecogs.com/svg.image?O(n^2)) time complexity. We can get the total number of moves to make two strings 
  ![](https://latex.codecogs.com/svg.image?s) & ![](https://latex.codecogs.com/svg.image?t) equal by doing ![](https://latex.codecogs.com/svg.image?\sum_{i=1}^{m}(\left|s_i-t_i\right|)).
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
