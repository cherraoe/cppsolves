#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        // begin
        int n; cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end());
        vector<int> pre(n+1);
        for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + b[i-1];

        // int l = 0, r = n, mid;
        int ms = 0;
        for (int j = 0; j < n; j++) {
            int i = a[j];
            int nsw = n - (lower_bound(a.begin(), a.end(), i) - a.begin());
            int nk = upper_bound(pre.begin(), pre.end(), nsw) - pre.begin() - 1;

            if (ms < nk*i) {
                ms = nk*i;
            }
        }

        cout << ms << endl;

    } // end
}
