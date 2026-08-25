#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, d; cin >> n >> k >> d;
    // ans is number of paths matching conditions, % 1000000007
    // N is the allowed weight to count
    // K is the k tree
    // needs at least one edge == D
    int ans;

    vector<vector<int>> dp(n+1, vector<int>(2,0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;
            j <= k && i-j >= 0;
            j++) {
            if (j >= d) {
                dp[i][1] = ((dp[i][1]%1000000007) + (dp[i-j][0]%1000000007) + (dp[i-j][1]%1000000007)) %1000000007;
            } else {
                dp[i][0] = (dp[i][0]+dp[i-j][0])%1000000007;
                dp[i][1] = (dp[i][1]+dp[i-j][1])%1000000007;
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     cout << dp[i][0] << " ";
    // }
    // cout << endl;
    // for (int i = 0; i <= n; i++) {
    //     cout << dp[i][1] << " ";
    // }
    ans = dp[n][1];
    cout << ans;
}
