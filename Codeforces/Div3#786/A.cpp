// author: Mushfiq_Talha
#include "bits/stdc++.h"

#define fast ios::sync_with_stdio(0);cin.tie(0)
#define tests int tst;cin>>tst;while(tst--)

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if(y % x) {
        cout << "0 0\n";
        return;
    }

    cout << "1 " << y / x << '\n';
}

int main() {
    fast;

    tests
        solve();

    return 0;
}
