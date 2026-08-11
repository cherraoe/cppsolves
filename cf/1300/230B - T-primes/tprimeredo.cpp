#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int x; cin >> x;
        int r1 = sqrtl(x);
        int r2 = sqrtl(r1);

        bool tp = false;
        if (r1*r1 == x && x > 1) {
            tp = true;
            for (int i = 2; i <= r2; i++) {
                if (x % i == 0) {
                    tp = false;
                    break;
                }
            }
        }

        cout << (tp ? "YES" : "NO") << endl;
    }
}
