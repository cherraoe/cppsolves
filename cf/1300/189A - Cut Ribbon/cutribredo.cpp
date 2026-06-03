#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c; cin >> n >> a >> b >> c;

    // MAKE EVERYTHING 1 INDEXED

    vector<int> dp(n+1, 0);
    if (a <= n) dp[a] = 1;
    if (b <= n) dp[b] = 1;
    if (c <= n) dp[c] = 1;

    for (int i = 1; i <= n; i++) {
        if (i >= a && dp[i-a] > 0) dp[i] = max(dp[i], dp[i-a]+1);
        if (i >= b && dp[i-b] > 0) dp[i] = max(dp[i], dp[i-b]+1);
        if (i >= c && dp[i-c] > 0) dp[i] = max(dp[i], dp[i-c]+1);
    }

    cout << dp[n];
}
