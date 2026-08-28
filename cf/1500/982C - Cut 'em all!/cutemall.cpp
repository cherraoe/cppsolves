#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj, dp, sz;

void dfs(int cu, int orig) {

    dp[cu][0] = 0;
    sz[cu][0] = 1;

    for (int nx : adj[cu]) {
        if (nx == orig) continue;
        dfs(nx, cu);

        dp[cu][0] += dp[nx][0];
        if (sz[nx][0]%2 == 0) {
            dp[cu][0]++;
        } else {
            sz[cu][0] += sz[nx][0];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.assign(n, {});
    dp.assign(n, vector<int>(2));
    sz.assign(n, vector<int>(2));

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1);

    if (sz[0][0]%2!=0) cout << -1;
    else cout << dp[0][0];
}
