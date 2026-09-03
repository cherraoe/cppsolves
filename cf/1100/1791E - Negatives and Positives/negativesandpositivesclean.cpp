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
        int perf = 0;
        int tny = 1e9;
        int neg = 0;
        for (int& x : a) {
            cin >> x;
            if (x <= 0) neg++;
            perf += abs(x);
            tny = min(tny, abs(x));
        }
        int c;
        if (neg%2==0) c = perf;
        else c = perf-2*tny;
        cout << c << "\n";
    }
}
