#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int pre = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pre += a[i];
    }

    int bc = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (!a[i]) {
            c++;
        } else {
            if (c-1 >= 0) {
                c--;
            } else {
                c = 0;
            }
        }
        bc = max(bc, c);
    }
    int out = pre+bc;

    if (bc == 0) out = pre-1;
    cout << out;
}
