#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& a, vector<int>& b, int l, int r, int d, int n) {
    // cout << "seeded " << l << " " << r << " with d:" << d << endl;

    int max = -1, maxp = -1;
    for (int i = l; i <= r; i++) {
        if (max < a[i]) {
            max = a[i];
            maxp = i;
        }
    }
    if (maxp != -1) {
        // cout << "wrote " << d << " to " << maxp << endl;
        b[maxp] = d;
        if (maxp > 0) dfs(a, b, l, maxp-1, d+1, n);
        if (maxp+1 < n) dfs(a, b, maxp+1, r, d+1, n);
    }
}

int main() {
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {

        int n; cin >> n;
        vector<int> a(n), b(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        dfs(a, b, 0, n-1, 0, n);

        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }
}
