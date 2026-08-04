#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m, e; cin >> n >> m >> e;
        vector<int> l(n); //hurdle start
        vector<int> le(n); //hurdle leng
        vector<int> x(m); //powerup position
        vector<int> v(m); //powerup strength
        for (int i = 0; i < n; i++) {
            int r;
            cin >> l[i] >> r;
            le[i] = r-l[i]+1;
        }
        for (int i = 0; i < m; i++) {
            cin >> x[i];
            cin >> v[i];
        }

        int p = 1;
        int pused = 0;
        priority_queue<int> pq;

        int secondi = 0;

        for (int i = 0; i < n; i++) {
            if (p > (le[i])) { //free pass
                continue;
            } else {
                // cout << "checked " << x[secondi] << " < " << l[i] << endl;
                while (secondi < m && x[secondi] < l[i]) {
                    pq.push(v[secondi]);
                    secondi++;
                    // cout << "pushed v[" << secondi << "]: " << v[secondi] << endl;
                    // cout << "checked " << x[secondi] << " < " << l[i] << endl;
                }

                while (!pq.empty() && p <= le[i]) {
                    // cout << "used pqv =  " << pq.top() << endl;
                    p += pq.top(); pq.pop();
                    pused++;
                }
                // cout << "was " << p << " smaller than " << l[i] << endl;
                if (p <= le[i]) {
                    pused = -1;
                    break;
                }
            }
        }
        cout << pused << endl;
    }
}
