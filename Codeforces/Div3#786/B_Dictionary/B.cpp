// author: Mushfiq_Talha
#include "bits/stdc++.h"

#define fast ios::sync_with_stdio(0);cin.tie(0)
#define tests int tst;cin>>tst;while(tst--)

using namespace std;

void solve() {
    string s;
    cin >> s;

    cout << s[0]*25 + s[1] - 26*'a' + (s[1] < s[0] ? 1 : 0) << '\n';
}

int main() {
    fast;

    tests
        solve();

    return 0;
}
