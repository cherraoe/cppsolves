#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int t = 0; t < n; t++) {
        int x; cin >> x;

        bool tp = false;
        int r = (long long) sqrtl((long double) x);
        int rr = sqrtl(r);
        if (r*r==x && x > 1) {
            tp = true;

            for (int i = 2; i <= rr; i++) {
                if (x % i == 0) {
                    tp = false;
                    break;
                }
            }
        }

        string o = tp ? "YES" : "NO";
        cout << o << endl;
    }
}
