#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, s; cin >> n >> s;
    int smax = s, smin = s;
    vector<int> a(n), b;
    bool fail = false;
    if (s > 0 || n == 1) {

        for (int i = n-1; i >= 0; i--) {
            a[i] = clamp(smax, 0, 9);
            smax -= a[i];
        }
        if (smax > 0) {
            fail = true;
        } else if (a[0] == 0) {

            int i = 0;
            while (i < n && a[i] == 0) {
                i++;
            }
            a[i]--;
            if (s > 0) a[0] = 1;
        }

        for (int i = 0; i < n; i++) {
            b.push_back(clamp(smin, 0, 9));
            smin -= b[i];
        }
    } else {
        fail = true;
    }

    if (fail) {
        cout << "-1 -1";
    } else {
        for (int x : a) cout << x;
        cout << " ";
        for (int x : b) cout << x;
    }
}
