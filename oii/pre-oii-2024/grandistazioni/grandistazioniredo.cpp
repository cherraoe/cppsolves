#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define ll long long

int findnxt(int cu, int n, vector<ll>& nxt, vector<int>& v) {
    int root = cu;
    while (root != -1 && root != n - 1 && v[root] == -1) {
        root = nxt[root];
    }
    while (cu != root) {
        int next_node = nxt[cu];
        nxt[cu] = root;
        cu = next_node;
    }
    return root;
}

ll viaggia(int n, int m, vector<int> a, vector<int> b, vector<int> t, vector<int> v, vector<int> w) {
    // n stations
    // m edges
    // a root b destination t time for m
    // v[i] -1 if no error, otherwise w time to error for i station

    vector<vector<tuple<int,ll>>> adj(n);
    vector<vector<tuple<int,ll>>> inverseadj(n); // for nxt and sisters
    for (int i = 0; i < m; i++) {
        adj[a[i]].push_back({b[i], t[i]});
        inverseadj[b[i]].push_back({a[i], t[i]});
    }

    vector<ll> nxt(n, -1), nxtcost(n, -1), totalcost(n, -1);
    priority_queue<tuple<ll,int>, vector<tuple<ll,int>>, greater<>> pq;
    pq.push({0, n-1});
    nxtcost[n-1] = 0;
    totalcost[n-1] = 0;
    while (!pq.empty()) {
        auto [ti, cu] = pq.top(); pq.pop();

        if (totalcost[cu] != -1 && totalcost[cu] < ti) continue;

        for (auto [nx, tc] : inverseadj[cu]) {
            if (totalcost[nx] > ti+tc || totalcost[nx] == -1) {
                totalcost[nx] = ti+tc;
                nxt[nx] = cu;
                nxtcost[nx] = tc;
                pq.push({ti+tc, nx});
            }
        }
    }
    // for (int x : nxt) cout << x << " ";
    // cout << endl;
    // for (int x : nxtcost) cout << x << " ";
    // cout << endl;
    // for (int x : totalcost) cout << x << " ";

    priority_queue<tuple<ll,int>, vector<tuple<ll,int>>, greater<>> q;
    q.push({0, 0});
    // first weight, second index

    while (!q.empty()) {
        auto [ti, cu] = q.top(); q.pop();
        if (cu == n-1) return ti;
        if (v[cu] != -1) {
            q.push({ti+w[cu], v[cu]});
            v[cu] = -1;
        } else {
            int nxx = findnxt(cu, n, nxt, v);
            q.push({ti+(totalcost[cu]-totalcost[nxx]), nxx});
        }

    }


    return 129;
}
