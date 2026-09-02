#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    // dp doesnt work cus too many possibilites (too many possible states)
    // priority queue doesnt work because its sequential and not total
    // brute force O(n^2) would tle
    // attempting dijkstra multi state because theres only potioncount and healthvalue? no, wouldnt work as i wouldn need 2e5*2e5 sized arr

    int c = 0;
    int h = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        h += a[i];
        c++;
        if (a[i] < 0) {
            pq.push(a[i]);
            // cout << "push("<<a[i]<<")\n";
        }
        if (h < 0) {
            while (!pq.empty() && h < 0) {
                auto worst = pq.top(); pq.pop();
                // cout << h << "+" << worst << " = " << h-worst<<"\n";
                h -= worst;
                c--;
            }
        }
    }
    cout << c;
}
