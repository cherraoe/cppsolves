#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> pq;
        priority_queue<int, vector<int>, greater<>> p;
        int neg = 0;
        for (int& x : a) {
            cin >> x;
            p.push(x);
            if (x <= 0) neg++;
        }
        neg = neg - (neg%2);

        while (!p.empty()) {
            int x = p.top(); p.pop();
            pq.push_back(x);
        }
        int c = pq[0];

        for (int i = 1; i < n; i++) {
            if (-pq[i]-pq[i-1] > pq[i]+pq[i-1]) {
                pq[i] = -pq[i];
                pq[i-1] = -pq[i-1];
                c += 2*pq[i-1];
            }
            c += pq[i];
        }
        cout << c << "\n";
    }
}
