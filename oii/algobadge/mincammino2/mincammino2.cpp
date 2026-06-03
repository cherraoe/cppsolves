#include <bits/stdc++.h>
#include <climits>
using namespace std;

// n is number of nodes
// m is edges (THEY ARE ONE DIRECTIONAL)
// x is rootn, y is nextn, p is price
// d should be the answers

void mincammino(int n, int m, vector<int> x, vector<int> y, vector<int> p, vector<long long>& d) {

    vector<vector<pair<long long,int>>> c(n);
    for (int i = 0; i < m; i++) {
        c[x[i]].push_back({
            p[i], // price first !!
            y[i], // then destination
        });
    }

    for (int i = 0; i < n; i++) d[i] = -1;
    d[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 0});
    // start first node explorer
    // {cost 0} for {node 0} with so far

    while (!q.empty()) {
        auto [cost, rootn] = q.top(); q.pop();

        if (d[rootn] < cost) continue;
        d[rootn] = cost;

        for (auto [nextc, nextn] : c[rootn]) {
            long long pricetoseed = cost + nextc;
            if (d[nextn] == -1 || d[nextn] > pricetoseed) {
                q.push({pricetoseed, nextn});
                d[nextn] = pricetoseed;
            }
        }
    }
}
