#include <bits/stdc++.h>
using namespace std;

int machete(int n, int k, vector<int> p) {
    //k is the height limit
    vector<vector<int>> t(n);
    int ans = 0;
    for (int i = 1; i < n; i++) {
        t[p[i]].push_back(i);
    }
    queue<pair<int,int>> q;
    q.push({0, 1});
    while (!q.empty()) {
        auto [pos, v] = q.front(); q.pop();
        for (int nx : t[pos]) {
            if (v >= k) { q.push({nx, 2}); ans++; }
            else q.push({nx,v+1});
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
