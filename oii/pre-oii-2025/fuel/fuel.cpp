#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<int> c, pre;

void pianifica (int N, int K, vector<int> C) {
    n = N;
    k = K;
    c.assign(n, 0);
    int b = 0, s = 0;
    while (s < n) {
        // cout << b<<"-"<<s<<">="<<k<< "?";
        if (s-b >= k) {
            // cout << " yeah";
            b++;
        } else {
            // cout << " no";
        }
        int l = b;
        while (l <= s) {
            if (C[l] < C[b]) {
                b = l;
            }
            l++;
        }

        // cout << "\n";
        // cout << "on s=" << s << " wrote C["<<b<<"]="<<C[b]<<"\n";
        c[s] = C[b];
        s++;
    }
    pre.assign(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + c[i-1];
        // cout << c[i-1] << " ";
    }
    // cout << endl;
    // for (int x : pre) cout << x << " ";
    // cout <<"\n";
}

long long viaggia (int l, int r) {
    return pre[r]-pre[l];
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL
int main () {

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int &c: C) cin >> c;
    pianifica(N, K, C);

    int Q; cin >> Q;

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << viaggia(l, r) << endl;
    }
}
#endif
