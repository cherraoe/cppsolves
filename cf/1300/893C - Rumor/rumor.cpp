#include <bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>>& a, vector<int>& c, vector<bool>& conq, int i) {
    int lowest = c[i];
    for (int next : a[i]) {
        if (conq[next]) continue;
        conq[next] = true;
        lowest = min(lowest, dfs(a, c, conq, next));
    }
    return lowest;
}

int main() {
    int n, m; cin >> n >> m;
    vector<int> c(n);
    vector<bool> conq(n, false);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> a(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    long long gold = 0;
    for (int i = 0; i < n; i++) {
        if (conq[i]) continue;
        conq[i] = true;
        gold += dfs(a, c, conq, i);
    }
    cout << gold;
}
