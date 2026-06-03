#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int b; cin >> b;
        int l = 0, r = n, mid;
        while (l < r) {
            mid = l + (r-l)/2;
            if (b < a[mid]) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        cout << r << " ";
    }
}
