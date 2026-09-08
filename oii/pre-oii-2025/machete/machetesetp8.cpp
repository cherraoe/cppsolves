#include <bits/stdc++.h>
using namespace std;

int machete(int n, int k, vector<int> p) {
    int ans = 0;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        adj[p[i]].push_back(i);
    }

    queue<int> q;
    stack<int> s;
    q.push(0);
    while (!q.empty()) {
        int root = q.front(); q.pop();
        for (int next : adj[root]) {
            q.push(next);
            s.push(next);
        }
    }

    vector<int> h(n, 0);
    while (!s.empty()) {
        int node = s.top(); s.pop();
        if (h[node] >= k-2 && p[node] != 0) {
            p[node] = 0;
            ans++;
        } else {
            h[p[node]] = max(h[p[node]], h[node]+1);
        }
    }

    return ans;
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
