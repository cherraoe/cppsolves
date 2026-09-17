#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), [] (auto& x, auto& y) {
        if (
            (x.second + y.first) < (x.first + y.second)
        ) return true;
        return false;
    });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto [a, b] = v[i];
        ans += a * i;
        ans += b * (n-(i+1));
    }

    cout << ans;
}
