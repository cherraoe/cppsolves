#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<vector<int>> adj;
vector<int> d, s;
priority_queue<pair<int,int>> pq; //farthest industry cities
unordered_map<int, bool> mp;

void dfspush(int root, int prev) {
    s[root] = 1;
    for (int nx : adj[root]) {
        if (nx == prev) continue;
        d[nx] = d[root]+1;
        dfspush(nx, root);
        s[root] += s[nx];
    }
    pq.push({d[root], root});
}

pair<int,int> dfspop(int root, int prev) {
    // base case and values
    int env = mp[root];
    int hap = 0;
    for (int nx : adj[root]) {
        if (nx == prev) continue;
        auto [nxenv, nxhap] = dfspop(nx, root);
        env += nxenv;
        hap += nxhap;
    }
    if (!mp[root]) hap += env;
    return {env, hap};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    adj.assign(n, {});
    d.assign(n, 0);
    s.assign(n, 0);
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    d[0] = 1;
    dfspush(0, -1);

    // auto cmp = [](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
    //   if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
    //   return get<1>(a) > get<1>(b);
    // };
    // priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, decltype(cmp)> spq(cmp);
    priority_queue<tuple<int,int>> spq;

    for (int i = 0; !pq.empty(); i++) {
        auto [value, pos] = pq.top(); pq.pop();
        spq.push({value-s[pos], pos});
        // cout << i << ": "<< value <<" "<< s[pos] <<" "<< pos<< endl;
    }
    for (int i = 0; i < k; i++) {
        auto [value, pos] = spq.top(); spq.pop();
        // cout << value << " " << size << " " << pos << endl;
        mp[pos] = true;
    }

    auto [env, happy] = dfspop(0, -1);
    cout << happy;
}
