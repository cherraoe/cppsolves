#include <bits/stdc++.h>
using namespace std;
#define int long long



signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> pre(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }

    //brute force example
    int max = pre[n];
    if (max%3 != 0) { cout << 0; return 0; } // no need to worry about weird exceptions, guarantees sum divisible and safe
    int ans = 0;
    int th = max/3; // third
    vector<int> c(n+1, 0);
    for (int i = n-1; i >= 1; i--) {
        c[i] = (pre[i] == 2*th) ? c[i+1]+1 : c[i+1];
        // cout << "c["<<i<<"]="<<c[i]<<endl;
    }
    for (int i = 1; i < n; i++) {
        if (pre[i] == th) {
            ans += c[i+1];
        }
    }
    cout << ans;
}
