#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<ll> f;
vector<tuple<int,int,ll>> z;

void add(int i, ll val) {
    for (++i; i <= n; i += i&-i) {
        f[i] += val;
    }
}

ll qrypre(int i) {
    ll sum = 0;
    for (++i; i > 0; i -= i&-i) {
        sum += f[i];
    }
    return sum;
}

long long alleggerisci(int N, int M, vector<int> V, vector<int> L,
vector<int> R, vector<long long> K) {
    n = N;
    f.assign(n+1, 0);

    z.clear();
    for (int i = 0; i < M; i++) {
        z.push_back({L[i], R[i], K[i]});
    }
    sort(z.begin(), z.end(), [](const auto& a, const auto& b){
        auto [la, ra, ka] = a;
        auto [lb, rb, kb] = b;
        return ra < rb;
    });

    vector<ll> pre(n+1, 0);
    for (int i = 0; i < n; i++) {
        pre[i+1] = pre[i] + V[i];
    }

    ll ans = 0;
    for (int i = 0; i < M; i++) {
        auto [l, r, k] = z[i];
        ll weight = pre[r+1] - pre[l];
        ll offset = qrypre(r) - (l > 0 ? qrypre(l-1) : 0);
        if (weight-offset-k > 0) {
            ans += weight-offset-k;
            add(r, weight-offset-k);
        }
    }

    return ans;
}
