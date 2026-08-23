#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, L; cin >> n >> m >> L;
        vector<int> l(n), r(n);
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }
        vector<int> x(m), v(m);
        for (int i = 0; i < m; i++) {
            cin >> x[i] >> v[i];
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = r[i]-l[i]+1;
            // cout << p[i] << " ";
        }
        // cout << endl;

        int i = 0;
        int pui = 0;
        int jp = 1;

        int popc = 0;

        priority_queue<int> pu;
        while (i < n && popc != -1) {
            //load
            while (pui < m && x[pui] < l[i]) {
                pu.push(v[pui]);
                pui++;
            }
            while (p[i] >= jp) {
                // cout << p[i] << ">=" << jp << "\n";
                if (pu.empty()) {
                    popc = -1;
                    break;
                }
                jp += pu.top();
                // cout << "popped" << pu.top()<<"\n";
                pu.pop();
                popc++;
            }
            i++;
            // cout << "i++\n";
        }

        cout << popc << "\n";
    }
}
