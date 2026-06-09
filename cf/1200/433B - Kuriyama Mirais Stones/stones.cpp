#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> v(n);
    vector<int> preu(n+1, 0);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) preu[i] = preu[i-1] + v[i-1];

    vector<int> c = v;
    vector<int> pres(n+1, 0);
    sort(c.begin(), c.end());
    for (int i = 1; i <= n; i++) pres[i] = pres[i-1] + c[i-1];

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int t, l, r, ans; cin >> t >> l >> r;

        l--;
        if (t == 1) {
            ans = preu[r] - preu[l];
        } else {
            ans = pres[r] - pres[l];
        }

        cout << ans << endl;
    }
}
