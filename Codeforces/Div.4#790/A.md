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
