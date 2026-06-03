#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalmins = 240;
    int n; cin >> n;
    int k; cin >> k;
    int t = totalmins-k;

    vector<int> pre(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + 5*i;
    }

    int l = 0;
    int r = n;
    int mid = l + (r-l)/2;
    int c = 0;

    while (l <= r) {
        mid = l + (r-l)/2;
        //cout << t << " >= " << pre[mid] << endl;
        if (t >= pre[mid]) {
            //valid
            c = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
    }

    cout << c;
}
