#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // street length l
    // n lanters
    // 0 indexed, but ends at l
    // a[i] is the position of i lantern
    // find minimum d to have the whole street filled

    int n, l;
    cin >> n >> l;

    int low = l, high = 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < low) low = a[i];
        if (a[i] > high) high = a[i];
    }
    a.push_back(0-low);
    a.push_back(l+(l-high));

    sort(a.begin(), a.end());
    int maxleft = 0;
    int maxright = 0;

    for (int i = 1; i <= n+1; i++) {
        // cout << a[i] << " - " << a[i-1] << endl;
        // cout << a[i]-a[i-1] << endl;
        if (a[i]-a[i-1] > maxright-maxleft) {
            maxright = a[i];
            maxleft = a[i-1];
        }
    }

    int diffw = maxright-maxleft;
    if (diffw%2 == 0) {
        cout << diffw/2;
    } else {
        cout << diffw/2 << ".5";
    }
}
