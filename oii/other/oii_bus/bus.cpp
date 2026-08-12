#include <bits/stdc++.h>
#include <climits>
using namespace std;

int pianifica(int n, int l, vector<vector<int>> f) {

    vector<vector<int>> stl(n);
    vector<vector<int>> lts;
    for (int i = 0; i < l; i++) {
        vector<int> thislts;
        for (int x : f[i]) {
            stl[x].push_back(i);
            thislts.push_back(x);
        }
        lts.push_back(thislts);
    }

    vector<bool> vs(n, false);
    vector<bool> vl(l, false);
    vector<int> ans(n, INT_MAX);
    queue<tuple<int,int>> q;

    vs[0] = true;
    ans[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [cu, de] = q.front(); q.pop();

        if (ans[cu] < de) continue;

        for (int nl : stl[cu]) {
            if (vl[nl]) continue;
            vl[nl] = true;

            for (int ns : lts[nl]) {
                if (vs[ns]) continue;
                vs[ns] = true;

                if (ans[ns] > de+1) {
                    ans[ns] = de+1;
                    q.push({ns, de+1});
                }
            }
        }
    }
    int out = -1;
    if (ans[n-1] != INT_MAX) out = ans[n-1];
    return out;

    //this doesnt work, theyre one directional, see bus2.cpp
    // this only works if they were theoretically bidirectional
}
