#include <bits/stdc++.h>
using namespace std;

int tempo_massimo(int n, int a[], int b[]) {

    vector<vector<int>> dp(2, vector<int>(n+1, 0));

    // filling missing day 1 calc


    for (int i = 1; i <= n; i++) {
        // 0 is super
        int zer = max(dp[0][i-1], dp[1][i-1]);
        dp[0][i] = zer + a[i-1];

        // 1 is hyper the weird one
        if (i == 1) {
            dp[1][i] = b[i-1];
        } else {
            int one = max(dp[0][i-2], dp[1][i-2]);
            dp[1][i] = one + b[i-1];
        }
    }

    int ans = max(dp[0][n], dp[1][n]);

    return ans;
}
