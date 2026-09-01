#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> a, t;
vector<bool> subdead;
// vector<int> lz;
vector<int> pre(1e6+1, 1);

void prec() {
    for (int i = 2; i <= 1e6; i++) {
        for (int j = i; j <= 1e6; j+=i) {
            pre[j]++;
        }
    }
}

void build(int n, int l, int r) {
    if (l == r) {
        t[n] = a[l];
        if (t[n] <= 2) subdead[n] = true;
        return;
    }
    int m = l+(r-l)/2;
    build(2*n, l, m);
    build(2*n+1, m+1, r);
    t[n] = t[2*n] + t[2*n+1];
    subdead[n] = subdead[2*n] && subdead[2*n+1];
}

// void apply(int n) {
//     // this one slaps a post it note on it
//     lz[n]++;
// }

// void push(int n, int l, int r) {
//     // this one uses it and applies to childrn
//     while (lz[n] > 0) {
//         lz[n]--;
//         apply(2*n);
//         apply(2*n+1);

//     }
// }

void upd(int n, int l, int r, int lx, int rx) {
    // if (l >= lx && r <= rx) {
    //     apply(n);
    //     return;
    // }
    //
    if (l > rx || r < lx || subdead[n]) {
        return;
    }

    // cout << "updting " << n<<" "<<l<<" "<<r<<" "<<lx<<" "<<rx<<"\n";
    if (l == r) {
        // cout << "updated t["<<n<<"]="<<t[n]<<" > " << d(t[n]) << "\n";
        t[n] = pre[t[n]];
        if (t[n] <= 2) subdead[n] = true;
        return;
    }
    int m = l+(r-l)/2;
    if (!subdead[2*n]) upd(2*n, l, m, lx, rx);
    if (!subdead[2*n+1]) upd(2*n+1, m+1, r, lx, rx);
    t[n] = t[2*n] + t[2*n+1];
    subdead[n] = subdead[2*n] && subdead[2*n+1];
}

int qry(int n, int l, int r, int lx, int rx) {
    // break
    // cout<<l<<">="<<lx<<" && "<<r<<"<="<<rx<<"\n";
    if (l >= lx && r <= rx) {
        // cout << "ret t["<<n<<"]="<<t[n]<<"\n";
        return t[n];
    }
    if (l > rx || r < lx) {
        return 0;
    }
    // push
    // push(n, l, r);
    // children
    int m = l+(r-l)/2;
    return qry(2*n, l, m, lx, rx) + qry(2*n+1, m+1, r, lx, rx);
    // t[n] = t[2*n] + t[2*n+1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // find divisors of x by looping up to half of x and checking %%0
    // can store in a pre array for optimisation
    int n, q; cin >> n >> q;
    a.assign(n, 0);
    t.assign(4*n, 0);
    subdead.assign(4*n, false);
    // lz.assign(4*n, 0);
    for (int& x : a) cin >> x;

    prec();
    build(1, 0, n-1);

    while (q--) {
        int t, l, r; cin >> t >> l >> r; l--; r--;
        if (t == 1) {
            upd(1, 0, n-1, l, r);
        } else {
            // push(1, l, r);
            cout << qry(1, 0, n-1, l, r) << "\n";
        }
    }
}
