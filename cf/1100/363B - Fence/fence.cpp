#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int best = 1e16;
    int position = 0;

    vector<int> pre(n+1, 0);
    for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i-1];

    for (int i = k; i <= n; i++) {
        // cout << "testing " << best << " < " << pre[i]-pre[i-k] << "   i " << i-k << "  k " << k << endl;
        if (best > pre[i]-pre[i-k]) {
            best = pre[i]-pre[i-k];
            position = i-k;
        }
    }

    cout << position+1;
}
