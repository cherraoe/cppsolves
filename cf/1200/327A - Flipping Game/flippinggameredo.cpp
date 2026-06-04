#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int start = 0;
    vector<int> pre(n+1, 0);
    for (int i = 1; i <= n; i++) {
        start += a[i-1];
        pre[i] = pre[i-1] + (a[i-1] ? -1 : 1);
    }

    int best = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            best = max(best, pre[j]-pre[i]);
        }
    }
    if (best == 0) best = -1;
    cout << start+best;
}
