#include <bits/stdc++.h>
using namespace std;

signed main() {
    // cout << "a"<<endl;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << "b"<<endl;

    int n; cin >> n;
    vector<vector<int>> c(n+1);
    map<pair<int,int>, bool> v;
    for (int i = 1; i < n; i++) {
        int s, t; cin >> s >> t;
        c[s].push_back(t);
        c[t].push_back(s);
        v[{s,t}] = true;
    }
    // cout << "c"<<endl;

    vector<int> out;
    vector<int> ans(n+1, -1);

    int bc = INT_MAX;

    //calculating first
    int cost = 0;
    vector<bool> vs(n+1, false);
    queue<int> q;
    vs[1] = true;
    q.push(1);
    while (!q.empty()) {
        auto cu = q.front(); q.pop();
        for (int nx : c[cu]) {
            if (vs[nx]) continue;
            vs[nx] = true;
            q.push(nx);
            if (v[{cu,nx}]) continue;
            cost++;
        }
        if (cost > bc) break;
    }
    ans[1] = cost;

    vector<bool> mvs(n+1, false);
    queue<int> mq;
    mvs[1] = true;
    mq.push(1);

    //meta
    while (!mq.empty()) {
        auto cu = mq.front(); mq.pop();
        for (int nx : c[cu]) {
            if (mvs[nx]) continue;
            mvs[nx] = true;
            mq.push(nx);
            if (v[{cu, nx}]) {
                ans[nx] = ans[cu]+1;
            } else {
                ans[nx] = ans[cu]-1;
            }
        }
    }

    // final
    for (int i = 1; i < n+1; i++) {
        // cout << ans[i] <<"x\n";
        if (bc > ans[i]) {
            bc = ans[i];
            out = {i};
        } else if (bc == ans[i]) {
            out.push_back(i);
        }
    }

    //output
    cout << bc << endl;
    for (int o : out) cout << o << " ";
}
