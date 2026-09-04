#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        int a = 1;
        for (int d = 2; d*d <= n; d++) {
            if (n%d == 0) {
                a = n/d;
                break;
            }
        }
        cout << a << " " << n-a << "\n";
    }
}
