#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> build(int y, int x, int n, int m) {
    vector<pair<int,int>> reply;

    if (y > 0) reply.push_back({y-1, x});
    if (y+1 < n) reply.push_back({y+1, x});
    if (x > 0) reply.push_back({y, x-1});
    if (x+1 < m) reply.push_back({y, x+1});

    return reply;
}

void dfs(int y, int x, int n, int m, queue<pair<int,int>>& q, vector<vector<int>>& mz, vector<vector<bool>>& fr) {
    fr[y][x] = 0;

    for (auto [ny, nx] : build(y, x, n, m)) {
        if (mz[ny][nx] == 0 && fr[ny][nx]) {
            dfs(ny, nx, n, m, q, mz, fr);
        }
    }

    q.push({y, x});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> mz(n, vector<int>(m));
    vector<vector<bool>> fr(n, vector<bool>(m, true));
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < m; j++) {
            mz[i][j] = line[j]=='#' ? 1 : 0;
        }
    }

    int fy = 0, fx = 0;
    bool srcing = true;
    while (srcing) {
        if (mz[fy][fx] == 0) {
            srcing = false;
        } else {
            if (fx+1 >= m) {
                fx = 0;
                fy++;
            } else {
                fx++;
            }
        }
    }

    queue<pair<int,int>> q;
    dfs(fy, fx, n, m, q, mz, fr);

    for (int i = 0; i < k; i++) {
        auto [y, x] = q.front(); q.pop();
        mz[y][x] = 2;
    }

    for (int i = 0; i < n; i++) {
        string line;
        for (int j = 0; j < m; j++) {
            if (mz[i][j] == 2) {
                line.push_back('X');
            } else if (mz[i][j] == 1) {
                line.push_back('#');
            } else {
                line.push_back('.');
            }
        }
        cout << line << endl;
    }
}
