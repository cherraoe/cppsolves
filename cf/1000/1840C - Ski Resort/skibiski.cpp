#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n, k, q; cin >> n >> k >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        //k is number of days
        //q is max temp comfy

        int l = 0, r = 0;
        int c = 0;
        int minic = 0;
        while (l < n) {
            if (r >= n || a[r] > q) {
                l = r+1;
                r = l;
                minic = 0;
            } else {
                if (r-l >= k-1) {
                    minic++;
                    c += minic;
                }
                r++;
            }
        }
        cout << c << endl;
    } // end test case
}
