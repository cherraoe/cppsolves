#include <bits/stdc++.h>
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
    queue<pair<int,int>> q;

    queue<int> update;

    vector<bool> pu(n+1, false);
    vector<bool> gu(m, false);

    for (int i = 1; i <= n; i++) {
        if (ans[i] == -1) {


            q.push({i, 1});
            update.push(i);
            pu[i] = 1;
            while (!q.empty()) {
                auto [cu, cv] = q.front(); q.pop();

                for (int ng : ptg[cu]) {
                    if (gu[ng]) continue;
                    gu[ng] = 1;

                    for (int np : gtp[ng]) {
                        if (pu[np]) continue;
                        pu[np] = 1;

                        q.push({np, cv+1});
                        update.push(np);
                    }
                }
            }
            int updatev = update.size();
            while (!update.empty()) {
                int x = update.front();
                ans[x] = updatev;
                update.pop();
            }
        }

        cout << ans[i] << " ";
    }
}
