#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, a, b;
        cin >> n >> a >> b;

        queue<pair<int,int>> q;
        //        root,depth
        vector<int> fresh(n, 1);
        int firstlamp;
        for (int i = 0; i < a; i++) {
            int in; cin >> in;
            q.push({in, 1}); //1 because 1 switch away from turning off
            fresh[in] = false; //so no weird loop backs
            firstlamp = in;
        }

        vector<vector<int>> d(n);
        for (int i = 0; i < b; i++) {
            int q, w; cin >> q >> w;
            d[q].push_back(w);
            d[w].push_back(q);
        }

        int firstdepth = 1;
        while (!q.empty()) {
            auto [root, depth] = q.front(); q.pop();

            for (int next : d[root]) {
                if (fresh[next]) {
                    fresh[next] = false;
                    q.push({next, depth+1});
                    if (firstdepth < depth+1) {
                        firstdepth = depth+1;
                        firstlamp = next;
                    }
                }
            }
        }

        cout << "Case #" << t << ": ";
        cout << firstlamp << " " << firstdepth;
        cout << endl;
    }
}
