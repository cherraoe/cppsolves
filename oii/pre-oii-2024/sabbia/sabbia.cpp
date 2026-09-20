#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
vector<int> v;
vector<tuple<int,int,ll>> z;
vector<ll> k;
int ans = 0;
vector<ll> t;

void build (int no, int l, int r) {
    if (l == r) {
        t[no] = v[l];
        return;
    }
    int mid = l+(r-l)/2;
    build(2*no, l, mid);
    build(2*no+1, mid+1, r);
    t[no] = t[2*no] + t[2*no+1];
}

void upd (int no, int l, int r, int targ, ll val) {
    t[no] -= val;
    if (l == r) return;
    int mid = l+(r-l)/2;
    if (mid >= targ) upd(2*no, l, mid, targ, val);
    else upd(2*no+1, mid+1, r, targ, val);
}

ll qry (int no, int l, int r, int lx, int rx) {
    if (l >= lx && r <= rx) {
        return t[no];
    }
    if (l > rx || r < lx) return 0;
    int mid = l+(r-l)/2;
    return
        qry(2*no, l, mid, lx, rx) +
        qry(2*no+1, mid+1, r, lx, rx);
}

long long alleggerisci(int N, int M, vector<int> V, vector<int> L, vector<int> R, vector<long long> K) {
    // n buildings
    // m zones
    // v weight
    // l r bounds (inclusive) , must be <= k

    n = N; m = M;
    v = V;
    for (int i = 0; i < m; i++) {
        z.push_back({L[i], R[i], K[i]});
    }
    k = K;

    t.assign(4*n, 0);

    build(1, 0, n-1);

    sort(z.begin(), z.end(), []
        (const auto& a, const auto& b) {
            auto [la, ra, va] = a;
            auto [lb, rb, vb] = b;
            return ra < rb;
    });

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        auto [l, r, k] = z[i];
        ll reduction = qry(1, 0, n-1, l, r)-k;
        if (reduction > 0) {
            upd(1, 0, n-1, r, reduction);
            ans += reduction;
        }
    }

    return ans;
}
