#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;
    for (int i = 0; i < n; i++) c[i] = a[i]-b[i];

    int ans = 0;

    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        auto ub = upper_bound(c.begin()+i+1, c.end(), -c[i]);
        if (ub != c.end()) ans += c.end() - ub;
    }

    cout << ans;
}
