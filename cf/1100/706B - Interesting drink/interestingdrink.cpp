#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int m; cin >> m;
        int ans = upper_bound(x.begin(), x.end(), m) - x.begin();
        cout << ans << endl;
    }
}
