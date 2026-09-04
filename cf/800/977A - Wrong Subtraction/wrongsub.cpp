#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    while (k--) {
        if (n%10 == 0) {
            int x = n/10;
            n = x;
        } else {
            n--;
        }
    }
    cout << n;
}
