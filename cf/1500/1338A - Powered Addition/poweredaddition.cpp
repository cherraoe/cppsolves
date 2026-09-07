#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;

        int h = -1e10;
        int v = 0;
        for (int i = 0; i < n; i++) {
            if (h < a[i]) {
                h = a[i];
            } else if (v < h-a[i]) {
                v = h-a[i];
            }
        }
        // cout << "  "<<v<<"\n";
        int ans = 1;
        if (v == 0) {
            ans = 0;
        } else {
            int c = 1;
            int pow = 1;
            // cout << c<<"<<"<<pow<<" = "<<(c << pow)<<"  < "<<v<<"\n";
            while ((c << pow) <= v) {

                pow++;
            }
            ans = pow;
        }
        cout << ans << "\n";
    }
}
