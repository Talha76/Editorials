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

  Let us say, we get $R$ different integers $L_1',L_2',L_3',...,L_R'$ by applying the operation to $L$ once. So we can 
  say that minimum $distance$ from $L$ to all of $L_i'$ is $1$. Because from $L$ there is no other minimal way to visit all $L_i'$. 
  Similarly, from each of the $L_i'$ we will get $x_i$ integers after applying the operation for the second time to all 
  of the $L_i'$. Here $x_i\leq R$, because after applying operation second time, we may get some integers which are the repeatation 
  of $L_i'$.  
  We repeat the steps and at each step, we record the distance of the integers.  

  This above can be implemented using BFS. While iterating a number $x$, we will apply the operation i.even. we will add the $RV_i$ 
  with $x$ and if the number is not visited before, then we will store the number in the queue, and we will update it's distance 
  by $distance[x + RV_i] = distance[x] + 1;$.  
  If it is possible to get $U$ from $L$, then $U$ will be visited once. Otherwise, $U$ will never be visited. (And obviously the 
  queue will not run into $\infty$. Because, we can visit at most 10000 numbers, and after visiting all of these numbers, the new 
  numbers will be already visited.) At the end, if $U$ was visited then the answer is $distance[U]$. And if not, then the answer 
  is $-1$.
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
  transitions $\\{(M, N), (M, -N), (-M, N), (-M, -N)\\}$.  
  ***Case 2:*** Applying the above procedure, similarly we get another 4 transitions $\\{(N, M), (N, -M), (-N, M), (-N, -M)\\}$.  
  These transitions indicates that $c=a+transition_i.first$ and $d=b+transition_i.second$.  

  There are two corner cases regarding the transitions. These are when $M=N$ and when $M=0\textit{ or } N=0$.

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

## [C - Morning Walk](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1537)

## [D - Crazy King](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2327)
<details>
  <summary>Summary</summary>

  You are given a $N\times M$ chessboard which contains any of these symbols $\\{'.','Z','A','B'\\}$. Cells containing $'Z'$ are the cells occupied by knights. $'.'$ means unoccupied cells.  

  You have to go to $'B'$ from $'A'$ satisfying the conditions below:  
  - You can move forward or backward by one step at a time diagonally, horizontally or 
  vertically i.e. like a king in a chessboard. (Because you are the king!)
  - You cannot move to a cell which is occupied by a knight.
  - If any of the knights can move to a cell in one move, then you cannot move to that 
  cell i.e. all accessible cells from the knights are blocked for you.  

  Find minimum distance from $B$ to $A$, or if it is not possible then, print as requested in the statement.
</details>
<details>
  <summary>Tutorial</summary>

  We can traverse through all possible accessible cells using BFS. While we are on a cell, 
  if the child cells (the cells to which we can go in one move) are not blocked by the above conditions, then we can visit the child cells and update its distance by 
  $distance[child]=distance[parent]+1$.  

  *How can we check if a cell is blocked?*  
  If we are on a cell and in one knight move from that cell we can go to a cell which is occupied by a knight then obviously our present cell is blocked. Another way to do this 
  is, before applying bfs, we can visit all the cells which are occupied by knights and 
  from each cell we can make one knight move and mark the new cells as blocked.  

  After completing this journey print the $distance[B]$ or print as requested in the statement if $B$ was never visited.
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
  int m, n;
  PII a, b;
  int d[101][101];
  vector<string> grid;
  vector<PII> horse_dir{{2, 1}, {-2, 1}, {2, -1}, {-2, -1},
                  {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
  vector<PII> king_dir{{1, 1}, {-1, 1}, {1, -1}, {-1, -1},
                      {1, 0}, {-1, 0}, {0,  1}, { 0, -1}};

  void findab() {
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        if(grid[i][j] == 'A')
          a = {i, j};
        if(grid[i][j] == 'B')
          b = {i, j};
      }
    }
  }

  bool is_valid(int x, int y) {
    if(x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 'Z')
      return false;
    if(grid[x][y] == 'B')
      return true;
    for(auto [s, t]: horse_dir) {
      int X = x + s, Y = y + t;
      if(X >= 0 && Y >= 0 && X < m && Y < n && grid[X][Y] == 'Z')
        return false;
    }
    return true;
  }

  void solve() {
    cin >> m >> n;
    grid.resize(m);
    for(auto &i: grid)
      cin >> i;

    findab();
    memset(d, -1, sizeof d);
    queue<PII> q;
    q.push(a);
    d[a.first][a.second] = 0;
    while(!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      for(auto [s, t]: king_dir) {
        int X = x + s, Y = y + t;
        if(is_valid(X, Y) && d[X][Y] == -1) {
          q.push({X, Y});
          d[X][Y] = d[x][y] + 1;
        }
      }
    }

    if(d[b.first][b.second] == -1)
      cout << "King Peter, you can't go now!";
    else
      cout << "Minimal possible length of a trip is " << d[b.first][b.second];
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

## [E - Sticker Collector Robot](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2931)
<details>
  <summary>Summary</summary>

  You are given a $N\times M$ grid which contains four characters-
  - '.' $\rightarrow$ Normal cell
  - '*' $\rightarrow$ Cell with sticker
  - '#' $\rightarrow$ Blocked cell
  - 'N' or 'S' or 'L' or 'O' denoting North, South, East and West respectively.  
  
  You will start at the cell with the alphabetic character facing the direction as stated above. And you are given a set of 
  instructions as a string $S$, which contains-
  - $D$ $\rightarrow$ Rotate 90 degree right from present facing direction
  - $E$ $\rightarrow$ Rotate 90 degree left from present facing direction
  - $F$ $\rightarrow$ Move one step forward  

  If you are on a cell containing sticker then you collect the sticker. 
  You cannot move forward to such cells which are blocked or which does not exist. If such command appears, then the command 
  is not executed i.e. you remain at your current cell. Show how many stickers can you collect.
</details>
<details>
  <summary>Tutorial</summary>

  The solution approach is simple. Let's say we are on cell $(a, b)$. The directions of this cell are-
  - $(a-1,b) \rightarrow$ North of $(a, b)$
  - $(a,b+1) \rightarrow$ East of $(a,b)$
  - $(a+1,b) \rightarrow$ South of $(a,b)$
  - $(a,b-1) \rightarrow$ West of $(a,b)$  
  
  Now, we have to store all of these transitions in such a way that we can easily convert the facing direction according to the 
  instruction. We can do that by storing the directions in an array in a *clockwise* or *anti-clockwise* direction. An example 
  is: $direction\in \\{(-1,0),(0,1),(1,0),(0,-1)\\}$(Clockwise).  
  Let's define the present facing direction as $direction_i$. So, if we have to execute $D$, we can apply the transition 
  $direction_{i+1}$ and if we have to execute $E$, we can apply the transition $direction_{i-1}$. Similarly, we can do 
  vice-versa in case of $anti-clockwise$ direction. **Note:** The value of $i$ changes in a cyclic manner between $[0, 3]$.  
  Then in each cell we visit, if we get a sticker, then we increase the sticker counter by $1$, and remove the sticker from that 
  that cell. Finally, we print out the value of the sticker counter.
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

  const bool multi_test = false;
  int n, m, s, direction;
  string t;
  vector<string> g;
  vector<PII> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

  PII initialize() {
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(isalpha(g[i][j])) {
          switch(g[i][j]) {
            case 'N': direction = 0;
              break;
            case 'S': direction = 2;
              break;
            case 'L': direction = 1;
              break;
            default: direction = 3;
          }
          return {i, j};
        }
      }
    }
    return {-1, -1};
  }

  bool is_valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m && g[x][y] != '#';
  }

  void solve() {
    PII pos = initialize();
    int cnt = 0;
    for(auto c: t) {
      switch(c) {
        case 'D': direction = (direction + 1) % 4;
          break;
        case 'E': direction = (direction + 3) % 4;
          break;
        case 'F': {
          int x = pos.first + dir[direction].first,
              y = pos.second + dir[direction].second;
          if(is_valid(x, y)) {
            if(g[x][y] == '*') {
              cnt++;
              g[x][y] = '.';
            }
            pos = {x, y};
          }
        }
      }
    }

    cout << cnt << '\n';
  }

  int main() {
    fast;

    while(cin >> n >> m >> s && n) {
      g.resize(n);
      for(auto &i: g)
        cin >> i;
      cin >> t;
      solve();
    }

    return 0;
  }
  ```
</details>

## [F - Forwarding Emails](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3873)


## [G - Strongly Connected City](https://codeforces.com/problemset/problem/475/B)
<details>
  <summary>Tutorial</summary>

  We can approach in a brute force way since the constraints allow us to do so. At first, we define the direction of row $i$ as $row_i$, and direction of column $j$ as $col_j$. And also lets define our directions-

  - `>`$\rightarrow $ Right: $(0,1)$
  - `<`$\rightarrow $ Left: $(0,-1)$
  - `v`$\rightarrow $ Down: $(1,0)$
  - `^`$\rightarrow $ Up: $(-1,0)$  

  So, we can say, if we are on a cell $(i,j)$, then we can go right if $row_i=$`>`, and left if $row_i=$`<`. Again, we can go up if $col_i=$`^` and down if $col_i=$`v`.  
  So we start from all of the cells and from each cell, traverse the whole grid using BFS. After traversing the whole grid, we check if all cells are visited then continue starting from next cell, if any of the cell is unvisited, then print $NO$. After applying BFS from all of the cells, if all of the cells are visited in each traversal, then print $YES$.
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

  const bool multi_test = false;
  int n, m;
  vector<PII> h, v;

  bool is_valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
  }

  bool bfs(int x, int y) {
    queue<PII> q;
    vector<vector<bool>> vis(n, vector<bool>(m));
    q.push({x, y});
    vis[x][y] = true;
    while(!q.empty()) {
      x = q.front().first, y = q.front().second;
      q.pop();
      int X = x + h[x].first, Y = y + h[x].second;
      if(is_valid(X, Y) && !vis[X][Y]) {
        vis[X][Y] = true;
        q.push({X, Y});
      }
      X = x + v[y].first, Y = y + v[y].second;
      if(is_valid(X, Y) && !vis[X][Y]) {
        vis[X][Y] = true;
        q.push({X, Y});
      }
    }

    return all_of(all(vis), [](vector<bool> &v) {
      for(auto i: v)
        if(!i)
          return false;
      return true;
    });
  }

  void solve(int kase) {
    string hori, verti;
    cin >> n >> m >> hori >> verti;

    h.resize(n), v.resize(m);
    for(int i = 0; i < n; i++)
      h[i] = (hori[i] == '>' ? PII{0, 1} : PII{0, -1});
    for(int i = 0; i < m; i++)
      v[i] = (verti[i] == 'v' ? PII{1, 0} : PII{-1, 0});

    for(int i = 0; i < n; i++) {
      for(int j = 0; j < m; j++) {
        if(!bfs(i, j)) {
          cout << "NO\n";
          return;
        }
      }
    }

    cout << "YES\n";
  }

  int main() {
    fast;

    tests
      solve(kase);

    return 0;
  }
  ```
</details>

## [H - Tree Recovery](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=477)
<details>
  <summary>Tutorial</summary>

  At first let's know about the in-order, pre-order, and post-order traversal of a tree.  
  1. In an in-order traversal, $\textit{Left Subtree, Root, Right Subtree}$ order is maintained.
  2. In an pre-order traversal, $\textit{Root, Left Subtree, Right Subtree}$ order is maintained.
  3. In an post-order traversal, $\textit{Left Subtree, Right Subtree, Root}$ order is maintained.

  So, when we are given a pre-order and in-order traversal of a tree, we can surely get the root of the tree which is the first character of the pre-order traversal. Let's say, in the in-order traversal, we get the root at position $i$. So, the left subtree belongs in $inorder[:(i-1)]$, and right subtree belongs in $inorder[(i+1):]$. And, we keep track of our index in the pre-order traversal to track the root using $j$. Initially, $j=0$. Now, the root of the left subtree is obviously the next character after the root of the main tree i.e. $j=1$. After extracting the left subtree in this way, we will update our $j$ continuously and after traversing the whole left subtree, we will get $j$ in the right subtree root. Then we can traverse the right subtree.  
  So, we can summarize the above algorithm as follows: 
  1. Initialize tree range $\\{l,r\\}=\\{0,n - 1\\}$ (let's assume length of the traversal is n).
  2. Define pre-order traversal variable as $j$ and in-order traversal variable as $i$ and initialize $j=0$.
  3. Find root in range $\\{l,r\\}$ and update $i=\textit{root in range l...r}$.
  4. Define left subtree from in-order traversal as $inorder[l:(i-1)]$, and enter the left subtree and find root $j+1$.
  5. Define right subtree from in-order traversal as $inorder[(i+1):r]$ and enter the right subtree and find root $j+1$(this j will be updated after the left tree traversal).
  6. First traverse whole of the left subtree by updating the range $\\{l,r\\}=\\{l,(i-1)\\}$ and go back to $step 3$.
  7. Then traverse whole of the right subtree by updating the range $\\{l,r\\}=\\{(i+1):r\\}$ and go back to $step 3$.
</details>
<details>
  <summary>Solution 1</summary>

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

  const bool multi_test = false;
  // vector<vector<int>> tree;
  string in, pre, post;

  // void post_order(int node) {
  //   for(auto child: tree[node])
  //     post_order(child);
  //   cout << char(node + 65);
  // }

  int recover_tree(int &i, int l, int r) {
    if(l == r)
      return -1;
    if(r - l == 1) {
      post += pre[i];
      return pre[i];
    }

    int j, root = pre[i];
    for(j = l; j < r; j++)
      if(in[j] == root)
        break;
    root -= 65;

    int child = recover_tree(++i, l, j);
    if(child == -1)
      i--;
    // else
    //   tree[root].push_back(child);
    child = recover_tree(++i, j + 1, r);
    if(child == -1)
      i--;
    // else
    //   tree[root].push_back(child);

    post += (65 + root);
    return root;
  }

  void solve() {
    int i = 0;
    // tree.assign(in.size(), vector<int>(0));
    recover_tree(i, 0, in.size());
    cout << post << '\n';
    post.clear();
    // post_order(0);
  }

  int main() {
    // fast;

    while(cin >> pre >> in)
      solve();

    return 0;
  }
  ```
</details>
<details>
  <summary>Solution 2</summary>

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

  const bool multi_test = false;
  vector<vector<int>> tree;
  string in, pre;

  void post_order(int node) {
    for(auto child: tree[node])
      post_order(child);
    cout << char(node + 65);
  }

  int recover_tree(int &i, int l, int r) {
    if(l == r)
      return -1;
    if(r - l == 1) {
      return pre[i] - 65;
    }

    int j, root = pre[i];
    for(j = l; j < r; j++)
      if(in[j] == root)
        break;
    root -= 65;

    int child = recover_tree(++i, l, j);
    if(child == -1)
      i--;
    else
      tree[root].push_back(child);
    child = recover_tree(++i, j + 1, r);
    if(child == -1)
      i--;
    else
      tree[root].push_back(child);

    return root;
  }

  void solve() {
    int i = 0;
    tree.assign(in.size(), vector<int>(0));
    recover_tree(i, 0, in.size());
    post_order(pre[0] - 65);
    cout << '\n';
  }

  int main() {
    // fast;

    while(cin >> pre >> in)
      solve();

    return 0;
  }
  ```
</details>

