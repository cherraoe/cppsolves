#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int n; cin >> n;

        int doubler = 1;
        while (doubler*2 <= n) {
            doubler *= 2;
        }
        int ans = 1 + (n-doubler)*2;

        cout << ans << endl;
    }
}
