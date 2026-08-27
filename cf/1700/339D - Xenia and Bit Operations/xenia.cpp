#include <bits/stdc++.h>
#include <cmath>
using namespace std;

vector<int> a, t;

bool build(int pos, int l, int r) {
    if (l == r) {
        t[pos] = a[l];
        // cout <<"wrote a["<<l<<"]="<<a[l]<<" to t[" <<pos<<"]="<<t[pos]<<"\n";
        return 0;
    }
    int mid = l+(r-l)/2;
    build(2*pos, l, mid);
    bool type = build((2*pos)+1, mid+1, r);
    // type false if or
    // type true if xor
    if (type) t[pos] = t[pos*2] ^ t[(pos*2)+1];
    else t[pos] = t[pos*2] | t[(pos*2)+1];
    return (!type);
}

bool upd(int pos, int l, int r, int p, int b) {
    if (l == r) {
        t[pos] = b;
        // cout <<"wrote "<<b<<" to t[" <<pos<<"]="<<t[pos]<<"\n";
        return 0;
    }
    int mid = l+(r-l)/2;
    bool type = 1;
    if (p <= mid) {
        type = upd(2*pos, l, mid, p, b);
    } else {
        type = upd((2*pos)+1, mid+1, r, p, b);
    }

    if (type) t[pos] = t[pos*2] ^ t[(pos*2)+1];
    else t[pos] = t[pos*2] | t[(pos*2)+1];
    // cout <<"wrote t[" <<pos<<"]="<<t[pos]<<"\n";
    return (!type);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int siz = pow(2, n);
    a.assign(siz, 0);
    t.assign(siz*2, 0);
    for (int& x : a) cin >> x;

    build(1, 0, siz-1);

    for (int tc = 0; tc < m; tc++) {

        int p, b; cin >> p >> b;
        upd(1, 0, siz-1, --p, b);
        cout << t[1] << "\n";
    }
}
