#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int machete(int n, int k, vector<int> p) {
    vector<vector<int>> adj(n);
    vector<int> h(n, 0);
    for (int i = 1; i < n; i++) {
        // pushing this node to its parent;
        adj[p[i]].push_back(i);
    }

    // pushing reverse bfs order
    queue<int> q;
    q.push(0);
    stack<int> sq;
    while (!q.empty()) {
        int cu = q.front(); q.pop();
        for (int nx : adj[cu]) {
            q.push(nx);
            sq.push(nx);
        }
    }

    int cuts = 0;
    while (!sq.empty()) {
        int cu = sq.top(); sq.pop();
        if (h[cu] == k-2 && p[cu] != 0) {
            cuts++;
        } else {
            h[p[cu]] = max(h[p[cu]], h[cu]+1);
        }
    }

    return cuts;
}


// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(auto &i : P) cin >> i;

    cout << machete(N, K, P) << endl;
}
#endif
