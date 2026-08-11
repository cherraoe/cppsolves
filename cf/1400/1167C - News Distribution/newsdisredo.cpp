#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    vector<vector<int>> ptg(n+1);
    vector<vector<int>> gtp;

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        vector<int> thisgtp;
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            ptg[x].push_back(i);
            thisgtp.push_back(x);
        }
        gtp.push_back(thisgtp);
    }

    vector<int> ans(n+1, -1);
    vector<bool> vp(n+1, false);
    vector<bool> vg(m, false);
    queue<int> q;
    queue<int> f;

    for (int i = 1; i <= n; i++) {
        if (ans[i] == -1) {
            //bfs
            vp[i] = true;
            q.push(i);
            f.push(i);
            while (!q.empty()) {
                int cu = q.front(); q.pop();

                for (int ng : ptg[cu]) {
                    if (vg[ng]) continue;
                    vg[ng] = true;
                    for (int np : gtp[ng]) {
                        if (vp[np]) continue;
                        vp[np] = true;
                        q.push(np);
                        f.push(np);
                    }
                }
            }
            //flood
            int fv = f.size();
            while (!f.empty()) {
                ans[f.front()] = fv; f.pop();
            }
        }

        cout << ans[i] << " ";
    }
}
