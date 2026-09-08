#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findnxt(int node, vector<int>& v, int& n, vector<ll>& nextnode) {
    int root = node;
    while (node != -1 && node != n-1 && v[node] == -1) {
        node = nextnode[node]; // node is the one which goes to the end, root stays at the start
    }
    while (root != node) { // until theyre the same
        int nextofroot = nextnode[root]; // i save the next one of root
        nextnode[root] = node; // i change where it points, so it points to the end (node)
        root = nextofroot; // i make it proceed so i can update the next one
    }
    return node;
}

ll viaggia(int n, int m, vector<int> a, vector<int> b, vector<int> t, vector<int> v, vector<int> w) {
    vector<vector<tuple<int,int>>> adj(n);
    vector<vector<tuple<int,int>>> rdj(n);
    for (int i = 0; i < m; i++) {
        adj[a[i]].push_back({b[i], t[i]});
        rdj[b[i]].push_back({t[i], a[i]});
    }

    vector<ll> nextnode(n, -1), totaltime(n, -1);
    totaltime[n-1] = 0;
    priority_queue<tuple<ll,int>, vector<tuple<ll,int>>, greater<>> pq;
    pq.push({0, n-1});

    while (!pq.empty()) {
        auto [tt, root] = pq.top(); pq.pop();
        if (totaltime[root] < tt && totaltime[root] != -1) continue;
        for (auto [tc, next] : rdj[root]) {
            if (tt+tc < totaltime[next] || totaltime[next] == -1) {
                totaltime[next] = tt+tc;
                nextnode[next] = root;
                pq.push({tt+tc, next});
            }
        }
    }

    int node = 0;
    ll sum = 0;
    while (true) {
        if (node == n-1) return sum;
        if (v[node] != -1) {
            //have to go to wrong train
            sum += w[node];
            int forcedwrongtrain = v[node];
            v[node] = -1;
            node = forcedwrongtrain;
        } else {
            int nxt = findnxt(node, v, n, nextnode);
            sum += totaltime[node]-totaltime[nxt];
            node = nxt;
        }
    }
    return 129;
}
