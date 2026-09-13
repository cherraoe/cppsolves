#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, k;
vector<ll> c;
void pianifica (int N, int K, vector<int> C) {
    n = N; k = K;
    c.assign(C.begin(), C.end());
    nxt.assign(n+1, n);
    p.assign(n+1, 0);
    jd.assign(n+1, 0);

    stack<int> st;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    // pair { price at that station, index of that station }
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && (c[st.top()] >= c[i])) {
            st.pop();
        }

        if (!st.empty() && st.top() <= i+k) {
            nxt[i] = st.top();
            jd[i] = nxt[i]-i;
            p[i] = jd[i]*c[i];
        } else {
            while (!pq.empty() && pq.top().second > i+k) {
                pq.pop();
            }
            if (!pq.empty() && pq.top().second <= i+k) {
                nxt[i] = pq.top().second;
                jd[i] = nxt[i]-i;
                p[i] = (min(n, i + k)-i)*c[i];
                p[i] -= (k-jd[i])*c[i]; // latent discount
            }
        }


        st.push(i);
        pq.push({c[i], i});
    }
    cout << "c:   ";
    for (int x : c) cout << x << " ";
    cout << "\nnxt: ";
    for (int x : nxt) cout << x << " ";
    cout << "\np:   ";
    for (int x : p) cout << x << " ";
    cout << "\njd:  ";
    for (int x : jd) cout << x << " ";
    cout << "\n\n";

}

long long viaggia (int l, int r) {
    ll ans = 0;
    return 129;
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
