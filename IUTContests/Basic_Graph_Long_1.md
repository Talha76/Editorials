## [A - Unlock the Lock](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3312)
<details>
  <summary>Summary</summary>

  You are given 3 integers $L$, $U$, $R$, and an array $RV$ of $R$ intergers. You can do the following operation in one step-  
  - At each step, choose any interger $x$ from the given array $RV$ and replace $L$ with $(x+L)\mod10000$.  

  Let us define $distance$ from $i$ to $j$ as the number of operations needed to make $i=j$. Find the minimum distance from $L$ to $U$ 
  or state that it is impossible to make $U$ from $L$ using the above operation.
</details>
<details>
  <summary>Tutorial</summary>

  Let us say, we get $R$ different integers ${L_1}\',{L_2}\',{L_3}\',...,{L_R}\'$ by applying the operation to $L$ once. So we can 
  say that minimum $distance$ from $L$ to all of ${L_i}\'$ is $1$. Because from $L$ there is no other minimal way to visit all ${L_i}\'$. 
  Similarly, from each of the ${L_i}\'$ we will get $x_i$ integers after applying the operation for the second time to all 
  of the ${L_i}\'$. Here $x_i\leq R$, because after applying operation second time, we may get some integers which are the repeatation 
  of ${L_i}\'$.  
  We repeat the steps and at each step, we record the distance of the integers.  

  This above can be implemented using BFS. While iterating a number $x$, we will apply the operation i.e. we will add the $RV_i$ 
  with $x$ and if the number is not visited before, then we will store the number in the queue, and we will update it's distance 
  by $distance[x + RV_i] = distance[x] + 1;$.  
  If it is possible to get $U$ from $L$, then $U$ will be visited once. Otherwise, $U$ will never be visited. (And obviously the 
  queue will not run into $\infty$. Because, we can visit at most 10000 numbers, and after visiting all of these numbers, the new 
  numbers will be already visited.) At the end, if $U$ was visited then the answer is $distance[U]$. And if not, then the answer 
  is $1$.
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int t=1;if(multi_test)cin>>t;for(int kase=1;kase<=t;kase++)
  #define range(v, n) v, v + n
  #define all(v) v.begin(), v.end()
  #define toN(v, n) v.begin(), v.begin() + n
  #define ulta(v) v.rbegin(), v.rend()

  using namespace std;

  typedef long long ll;
  typedef pair<int, int> PII;

  const bool multi_test = false;
  int l, u, r;
  vector<int> v;

  void solve(int kase) {
    cout << "Case " << kase << ": ";
    vector<int> d(10000, -1);
    d[l] = 0;
    queue<int> q;
    q.push(l);
    while(!q.empty()) {
      int node = q.front();
      q.pop();
      for(auto i: v) {
        int n = (node + i) % 10000;
        if(d[n] == -1) {
          q.push(n);
          d[n] = d[node] + 1;
        }
      }
    }

    cout << (d[u] == -1 ? "Permanently Locked" : to_string(d[u]));
    cout << '\n';
  }

  int main() {
    fast;

    int kase = 1;
    while(cin >> l >> u >> r && r) {
      v.resize(r);
      for(auto &i: v)
        cin >> i;
      solve(kase++);
    }

    return 0;
  }
  ```
</details>

