#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<int>> ptg(n+1);
    vector<vector<int>> gtp;
    for (int i = 0; i < m; i++) {
        int k; cin >> k;

        vector<int> tg(k);
        for (int j = 0; j < k; j++) {
            cin >> tg[j];
            ptg[tg[j]].push_back(i);
        }
        gtp.push_back(tg);
    }

    vector<int> ans(n+1, -1);
    queue<int> fill;
    vector<bool> fresh(n+1, true);

    auto dfs = [&](auto& self, int curr) -> pair<int,bool> {
        // gonna return true if hit cache, return false if recomputed and need further summing from parents
        // also need to add to queue if false child
        // gonna check for cache hit before seeding
        int v;
        v = 1;
        for (int nextg : ptg[curr]) {
            for (int nextp : gtp[nextg]) {
                if (ans[nextp] != -1) {
                    return {ans[nextp], true};
                } else if (fresh[nextp]) {
                    fresh[nextp] = false;
                    auto [ri, rv] = self(self, nextp); // SPAWNING
                    if (rv) {
                        return {ri, true};
                    } else {
                        v += ri;
                        fill.push(nextp);
                    }
                }
            }
        }
        return {v, false};
    };

    for (int i = 1; i <= n; i++) {
        int out;
        if (ans[i]==-1) {
            // queue of indexes of array values i need to fill with the final value
            fresh[i] = false;
            auto hi = dfs(dfs, i);
            out = hi.first;
            while (!fill.empty()) {
                ans[fill.front()] = out; fill.pop();
            }
        } else {
            out = ans[i];
        }
        if (out > 1) out--;
        cout << out << " ";
    }
}
