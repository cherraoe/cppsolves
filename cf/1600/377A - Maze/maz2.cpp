#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> build_plus(int y, int x, int n, int m) {
    vector<pair<int,int>> reply;
    if (y-1 >= 0) reply.push_back({y-1, x});
    if (y+1 < n) reply.push_back({y+1, x});
    if (x-1 >= 0) reply.push_back({y, x-1});
    if (x+1 < m) reply.push_back({y, x+1});

    return reply;
}

void dfs(vector<vector<int>>& wa, vector<vector<int>>& explored, int ry, int rx, int n, int m, queue<pair<int,int>>& tobewalled) {
    explored[ry][rx] = 1;
    //my dfs needs to start from the root and only root the nearby ones. it should mark leaves (roots that seeded 0) for wall construction
    for (auto [ny, nx] : build_plus(ry, rx, n, m)) {
        if (explored[ny][nx] == 0 && wa[ny][nx] == 0) {
            dfs(wa, explored, ny, nx, n, m, tobewalled);
        }
    }
    tobewalled.push({ry, rx});
}

signed main() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> wa(n, vector<int>(m));
    vector<vector<int>> explored(n, vector<int>(m, 0));
    for (int y = 0; y < n; y++) {
        string row; cin >> row;
        for (int x = 0; x < m; x++) wa[y][x] = row[x] == '#' ? 1 : 0;
    }

    // find the first free
    int firsty = 0, firstx = 0;
    while (wa[firsty][firstx] != 0) {
        if (firstx+1 < m) {
            firstx++;
        } else {
            firstx = 0;
            firsty++;
        }
    }

    queue<pair<int,int>> tobewalled;
    dfs(wa, explored, firsty, firstx, n, m, tobewalled);

    for (int i = 0; i < k; i++) {
        auto [y, x] = tobewalled.front(); tobewalled.pop();
        wa[y][x] = 2;
    }

    // outputting
    for (int y = 0; y < n; y++) {
        string outputrow;
        for (int x = 0; x < m; x++) {
            char temp;
            if (wa[y][x] == 2) {
                temp = 'X';
            } else if (wa[y][x] == 1) {
                temp = '#';
            } else {
                temp = '.';
            }
            outputrow.push_back(temp);
        }
        cout << outputrow << endl;
    }
} // end
