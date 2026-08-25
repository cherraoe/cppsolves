#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        vector<int> a(k);
        for (int& x : a) { int xx; cin >> xx; x = xx-1; }

        vector<int> temp(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q;
        for (int i = 0; i < k; i++) {
            int tt; cin >> tt;
            temp[a[i]] = tt;
            q.push({tt, a[i]});
        } // temp first, then position second

        while (!q.empty()) {
            auto [tt, p] = q.top(); q.pop();
            if (tt > temp[p]) {
                // cout << tt<<">"<<temp[p]<<" at "<<p<<endl;
                continue; } // stale
            temp[p] = tt;
            for (int nx : {p-1,p+1}) {
                // if (nx == 4) cout << "writing " << tt+1 <<endl;
                if (temp[nx] > tt+1 && nx>=0 && nx<n) {
                    temp[nx] = tt+1;
                    // cout << "pushing " << tt+1 <<" "<<nx<<endl;
                    q.push({tt+1, nx});
                }
            }
        }

        for (int x : temp) cout << x << " ";
        cout << "\n";
    }
}
