#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> pre(n+1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i-1];

    for (int i = 0; i < m; i++) {
        int f, k;

        f = lower_bound(pre.begin(), pre.end(), b[i]) - pre.begin();
        k = b[i]-pre[f-1];

        cout << f << " " << k << endl;
    }
}
