#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t; cin >> n >> t;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    vector<int> pre(n+1);
    // cout << "0 ";
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
        // cout << pre[i] << " ";
    }
    // cout << endl;

    int ans = 0;

    auto initenditerator = lower_bound(pre.begin(), pre.end(), t);
    int initendn = initenditerator - pre.begin() - 1;
    int tcost = pre[initendn]; ans = max(ans, initendn);
    // cout << "tcost = " << tcost <<endl;
    // cout << "initendn or books = " << initendn << endl;

    int tavailable = t-tcost;
    // cout << tavailable << "tav\n";
    int l = 0, r = initendn-1;
    while (l < n) {
        // cout << tavailable << "tav\n";

        // cout << "l++\n";

        while (r+1 < n && tavailable >= a[r+1]) {
            tavailable -= a[r+1];
            // cout << tavailable << "tav\n";
            r++;
            // cout << "r++\n";
        }
        // cout << ans << " vs " << (r-l)+1 << endl;
        ans = max(ans, (r-l)+1);
        tavailable += a[l];
        l++;
    }

    cout << ans;
}
