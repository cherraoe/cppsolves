#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, f, a, b;
        cin >> n >> f >> a >> b;
        // n messages
        // f initial charge
        // a passive drain
        // b turn on/off

        vector<int> m;
        m.push_back(0);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m.push_back(x);
        }

        bool doable = true;
        for (int i = 1; i <= n; i++) {
            int passive = a*(m[i]-m[i-1]);
            // cout << "passive " << passive << endl;
            f -= min(passive, b);
            // cout << "check if " << f << endl;
            if (f <= 0) {
                doable = false;
                break;
            }
        }

        if (doable) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
