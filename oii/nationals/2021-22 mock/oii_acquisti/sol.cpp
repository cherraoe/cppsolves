#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> calcola(int T, int M, vector<ll> S, vector<ll> P) {
    vector<ll> pre(T+1, 0);
    for (int i = 1; i <= T; i++) {
        pre[i] = pre[i-1] + S[i-1]*(i-1);
    }

    vector<ll> pres(T+1, 0);
    for (int i = 1; i <= T; i++) {
        pres[i] = pres[i-1] + S[i-1];
    }
    vector<ll> out;
    for (int test = 0; test < M; test++) {
        ll cap = P[test];

        int lb = lower_bound(pre.begin(), pre.end(), cap) - pre.begin();
        ll n = pres[lb-1];
        cap -= pre[lb-1];
        if (lb <= T) {
            if (lb-1 != 0) n += min((ll)cap/(lb-1), S[lb-1]);
            else n += S[lb-1];
        }

        out.push_back(n);
    }
    return out;
}
