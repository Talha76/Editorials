## [A - Unlock the Lock](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3312)
<details>
  <summary>Summary</summary>

  You are given 3 integers $L$, $U$, $R$, and an array $RV$ of $R$ intergers. You can do the following operation in one step-  
  - At each step, choose any interger $x$ from the given array $RV$ and replace $L$ with $(x+L)\mod 10000$.  

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

  This above can be implemented using BFS. While iterating a number $x$, we will apply the operation i.even. we will add the $RV_i$ 
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

## [B - Knight in a War Grid](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3057)
<details>
  <summary>Summary</summary>

  You are given $R$, $C$ denoting number of rows and columns of an $R\times C$ grid. You are also given $M$, $N$ which denotes that we 
  can move from $(a, b)$ to $(c, d)$ iff any of this two conditions satisfies:
  $$|a-c|=M\textit{ and }|b-d|=N$$
  $$or$$
  $$|a-c|=N\textit{ and }|b-d|=M$$
  And then you are given $W$, denoting there are $W$ blocked cells which you cannot visit, and the blocked cells 
  $x_i, y_i$ are given.  

  Let us define a cell $even$, if the count of accessible cells from that cell in one move is even. And we define $odd$ 
  cell, if the number of accessible cells from that cell in one move is odd numbered. **Note:** All the blocked cells are 
  inaccessible.  
  You will start from cell $(0, 0)$ (Note: The grid is indexed in 0-base). You will visit all possible cells you can visit on your path and return to $(0, 0)$. After the visit output the number of even cells and odd cells.
</details>
<details>
  <summary>Tutorial</summary>

  We can use BFS to solve this problem. At the outset, let's find out the cells we can visit if we are presently in 
  cell $(a, b)$. Let's say we can go to $(c, d)$ in one move. So,   
  ***Case 1:*** $(|a-c|=M)\Rightarrow (a-c=M\textit{ or }-(a-c)=M)\Rightarrow (c=a-M\textit{ or }c=a+M)$ and 
  $(|b-d|=N)\Rightarrow (b-d=N\textit{ or }-(b-d)=N)\Rightarrow (d=b-N\textit{ or }d=b+N)$. So we get $2\times 2=4$ 
  transitions ${(M, N), (M, -N), (-M, N), (-M, -N)}$.  
  ***Case 2:*** Applying the above procedure, similarly we get another 4 transitions ${(N, M), (N, -M), (-N, M), (-N, -M)}$.  
  These transitions indicates that $c=a+transition_i.first$ and $d=b+transition_i.second$.  

  Now using these transitions, we can iterate through all the possible visitable cells, and in each cell we will 
  count the number of accessible cells from that cell. If the count is odd, we will increase the even counter by 
  else we will increase the odd counter by one.
</details>
<details>
  <summary>Solution</summary>

  ```cpp
  #include "bits/stdc++.h"

  #define fast ios::sync_with_stdio(0);cin.tie(0)
  #define tests int t=1;if(multi_test)cin>>t;for(int kase=1;kase<=t;kase++)
  #define caseout cout << "Case " << kase << ": "
  #define range(v, n) v, v + n
  #define all(v) v.begin(), v.end()
  #define toN(v, n) v.begin(), v.begin() + n
  #define ulta(v) v.rbegin(), v.rend()

  using namespace std;

  typedef long long ll;
  typedef pair<int, int> PII;

  const bool multi_test = true;
  int r, c, m, n, w, odd, even;
  set<PII> water, vis;
  queue<PII> q;

  bool is_valid(int x, int y) {
    return x >= 0 && y >= 0 && x < r && y < c && !water.count({x, y});
  }

  void solve(int kase) {
    cin >> r >> c >> m >> n >> w;
    while(w--) {
      int x, y;
      cin >> x >> y;
      water.emplace(PII{x, y});
    }

    vector<PII> dir {{m, n}, {-m, n}, {m, -n}, {-m, -n},
                     {n, m}, {-n, m}, {n, -m}, {-n, -m}};
    sort(all(dir));
    dir.erase(unique(all(dir)), dir.end());
    
    even = odd = 0;
    q.push({0, 0});
    vis.emplace(PII{0, 0});
    while(!q.empty()) {
      int x, y, X, Y, cnt = 0;
      x = q.front().first, y = q.front().second;
      q.pop();
      for(auto [a, b]: dir) {
        X = x + a, Y = y + b;
        if(is_valid(X, Y)) {
          cnt++;
          if(!vis.count({X, Y})) {
            vis.emplace(PII{X, Y});
            q.push({X, Y});
          }
        }
      }
      cnt & 1 ? odd++ : even++;
    }

    caseout << even << ' ' << odd << '\n';
    water.clear();
    vis.clear();
  }

  int main() {
    fast;

    tests
      solve(kase);

    return 0;
  }
  ```
</details>