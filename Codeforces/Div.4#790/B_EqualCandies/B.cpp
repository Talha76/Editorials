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
