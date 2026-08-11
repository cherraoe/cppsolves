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
    while (k > 0) {
        int l = b[0];
        int u = upper_bound(b.begin(), b.end(), l) - b.begin();
        int h;

        if (u >= b.size()) {
            int minisum = k/u;
            h = l+minisum;
        } else {
            h = b[u];
        }

        int cost = u*(h-l);

        if (k > cost) {
            if (cost==0) break;
            k -= cost;
            for (int i = 0; i < u; i++) b[i] = h;
        } else {
            int minisum = 0;
            while (k >= u) {
                minisum++;
                k -= u;
            }
            for (int i = 0; i < u; i++) b[i] += minisum;
            break;
        }
    }
    // cout << k << " k left\n";
    cout << b[0];
}
