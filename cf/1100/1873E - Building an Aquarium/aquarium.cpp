#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        int h = 0;
        int l = 0, r = 1e10;
        int mid;

        auto calc = [&]() -> bool {
            int tx = x;
            int i = 0;
            while (i < n && tx >= 0) {
                // cout << min(a[i], mid) <<"x on mid " << mid<<"\n";
                tx -= max((mid-a[i]), (int)0);
                i++;
            }
            // cout << "tx = " << tx <<"\n";
            return (tx>=0);
        };

        while (l <= r) {
            mid = l+(r-l)/2;
            if (calc()) {
                l = mid+1;
                h = max(h, mid);
            } else {
                r = mid-1;
            }
        }
        if (calc()) h = max(h, mid);

        cout << h << "\n";
    }
}
