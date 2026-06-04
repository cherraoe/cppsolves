#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int c = -1;
    queue<pair<int,int>> q;
    vector<bool> b(1e5, 1);
    q.push({n, 0});
    b[n] = 0;

    while (!q.empty() && c == -1) {
        auto [x, v] = q.front(); q.pop();
        if (x == m) c = v;
        if (b[x*2] && x < m*2) {
            b[x*2] = 0;
            q.push({x*2, v+1});
        }
        if (b[x-1] && x > 1) {
            b[x-1] = 0;
            q.push({x-1, v+1});
        }
    }

    cout << c;
}
