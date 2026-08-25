#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        vector<int> a(n);
        for (int& adsf : a) cin >> adsf;

        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = a[0];
        dp[0][1] = 1000;

        for (int i = 1; i < n; i++) {
            if (i >= 2) {
                dp[i][0] = min(
                dp[i-2][1]+a[i]+a[i-1],
                dp[i-1][1]+a[i]);
            } else {
                dp[i][0] = dp[0][0]+a[1];
            }

            if (i >= 2) {
                dp[i][1] = min(
                dp[i-2][0],
                dp[i-1][0]);
            } else {
                dp[i][1] = dp[i-1][0];
            }


            // if (i >= 2) {
            //     cout << i << "][0]) writing " << dp[i][0] << " from " << dp[i-2][1]+a[i]+a[i-1] << "/" << dp[i-1][1]+a[i] << endl;
            // } else {
            //     cout << i << "][0]) writing " << dp[i][0] << " from " << dp[i-1][1]+a[i] << endl;
            // }
            // if (i >= 2) {
            //     cout << i << "][1]) writing " << dp[i][1] << " from " << dp[i-2][0] << "/" << dp[i-1][0] << endl;
            // } else {
            //     cout << i << "][1]) writing " << dp[i][1] << " from " << dp[i-1][0] << endl;
            // }
        }
        cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
    }
}
