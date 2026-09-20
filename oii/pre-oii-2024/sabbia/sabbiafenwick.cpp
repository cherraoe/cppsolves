#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<ll> f;
vector<tuple<int,int,ll>> z;

void add (int i, ll val) {
    i++;
    while (i <= n) {
        f[i] += val;
        i += i&-i;
    }
}

ll sum (int i) {
    i++;
    ll s = 0;
    while (i > 0) {
        s += f[i];
        i -= i&-i;
    }
    return s;
}

ll qry (int l, int r) {
    return sum(r) - sum(l-1);
}

long long alleggerisci(int N, int M, vector<int> V, vector<int> L, vector<int> R, vector<long long> K) {
    n = N;
    f.assign(n+1, 0);

    z.clear();
    for (int i = 0; i < M; i++) {
        z.push_back({L[i], R[i], K[i]});
    }
    sort(z.begin(), z.end(), []
        (const auto& a, const auto& b) {
            auto [la, ra, va] = a;
            auto [lb, rb, vb] = b;
            return ra < rb;
    });

    vector<ll> pre(n+1, 0);
    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + V[i];
    }

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        auto [l, r, k] = z[i];
        ll red = (pre[r+1]-pre[l])
            - qry(l, r)
            - k;
        if (red > 0) {
            add(r, red);
            ans += red;
        }
    }

    return ans;
}
