#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, L; cin >> n >> m >> L;
        vector<int> l(n), r(n), x(m), v(m);
        for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
        for (int i = 0; i < m; i++) cin >> x[i] >> v[i];

        vector<int> le(n);
        for (int i = 0; i < n; i++) le[i] = r[i]-l[i]+1;

        int p = 1;
        int pu = 0;
        int pi = 0;

        priority_queue<int> pq;

        for (int i = 0; i < n; i++) {
            while (pi < m && x[pi] < l[i]) {
                pq.push(v[pi]);
                pi++;
            }
            while (!pq.empty() && p <= le[i]) {
                p += pq.top(); pq.pop();
                pu++;
            }
            if (pq.empty() && p <= le[i]) {
                pu = -1;
                break;
            }
        }
        cout << pu << endl;
    }
}
