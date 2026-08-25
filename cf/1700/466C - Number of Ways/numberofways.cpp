#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    // ans is how many ways i can divide this array so that the three parts are == in sum
    // initial brute force idea would be nested loops
    // could brute force and practice segtree ?
    // prefix sum could work if used right


    vector<int> pre(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }

    // while (l < n) {
    //     while (2*(pre[r]-pre[l]) < (pre[n]-pre[r])) {
    //         r++;
    //     }
    //     if (2*(pre[r]-pre[l]) == (pre[n]-pre[r])) {
    //         int lx = r, rx = n;
    //         int smid = -1;
    //         while (lx <= rx) {
    //             int mid = lx + (rx-lx)/2;
    //             if (pre[mid]-pre[r] == pre[n]-pre[mid]) {
    //                 ans++;
    //                 smid = mid;
    //                 break;
    //             } else if (pre[mid]-pre[r] > pre[n]-pre[mid]) {
    //                 rx = mid-1;
    //             } else {
    //                 lx = mid+1;
    //             }
    //         }
    //         if (smid != -1) {
    //             int mid = smid;
    //             while (pre[smid-1]==pre[smid]) {
    //                 smid--;
    //                 ans++;
    //             }
    //         }
    //     }

    //     //end
    //     l++;
    // }

    int sum = pre[n];
    if (sum%3 != 0) { cout << "0"; return 0; }
    int ans = 0;
    int l = 0, r = 0;
    while (l < n-2) {

    }

    cout << ans;
}
