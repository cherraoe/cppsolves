#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<int> b(n/2+1);
    for (int i = 0; i < n/2+1; i++) {
        b[i] = a[i+n/2];
    }

    vector<int> c(n/2+1);
    int prev = -1;
    int hold = -1;
    for (int i = n/2; i >= 0; i--) {
        if (prev == -1) {
            prev = b[i];
        }
        if (hold == -1) {
            hold = b[i];
        }

        if (prev != b[i]) {
            hold = prev;
        }

        c[i] = hold;
        prev = b[i];
    }

    int x = n/2+1;
    int xp = -1;
    vector<int> pre(n/2+2, 0);
    for (int i = 1; i < n/2+2; i++) {
        if (xp == -1) xp = b[i-1];

        pre[i] = pre[i-1];
        if (xp != b[i-1]) {
            pre[i] += c[i-1]-b[i-1];
        } else {
            pre[i] += c[i-1]-b[i-1];
        }
        xp = b[i-1];
    }

    int limit = b[
        (lower_bound(pre.begin(), pre.end(), k) - pre.begin()) - 1
        ];
    int out = limit;

    if (k >= n/2) {
        out += k/(n/2);
    }
    cout << out;
}
