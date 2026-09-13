#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define ll long long

int totallevels = 1;
int n, k;
vector<ll> c;
vector<vector<int>> up;
vector<vector<ll>> upc;
vector<ll> preopt;

void pianifica (int N, int K, vector<int> C) {
    //yeah
    // first init vars
    n = N; k = K;
    c.assign(C.begin(), C.end());
    while ((1 << totallevels) < n) {
        totallevels++;
    }

    // point to next cheapest within range

    vector<int> nxt(n+1, n);
    stack<int> st;
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && c[st.top()] >= c[i]) st.pop();
        if (!st.empty()) nxt[i] = st.top();
        st.push(i);
    }

    //create table
    up.assign(totallevels, vector<int>(n+1, n));
    upc.assign(totallevels, vector<ll>(n+1, 0));
    // first level of both
    up[0] = nxt;
    for (int i = 0; i < n; i++) {
        upc[0][i] = (ll) c[i] * (nxt[i]-i);
    }
    // building the other layers
    for (int l = 1; l < totallevels; l++) {
        for (int i = 0; i < n; i++) {
            int mid = up[l-1][i];
            up[l][i] = up[l-1][mid];
            upc[l][i] = upc[l-1][i] + upc[l-1][mid];
        }
    }
    //done here

    // building the prefix window for the smallest one
    // the dequeue is a mental mess im just gonna pq it
    vector<ll> optimal(n);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({c[i], i});
        auto [value, index] = pq.top();
        while (!pq.empty() && index <= i-k) {
            pq.pop();
            value = pq.top().first;
            index = pq.top().second;
        }
        optimal[i] = value;
    }
    preopt.assign(n+1, 0);
    for (int i = 0; i < n; i++) {
        preopt[i+1] = preopt[i]+optimal[i];
    }
}

ll spm (int l, int target) {
    if (l > target) return 0;
    ll sum = 0;
    for (int h = totallevels-1; h >= 0; h--) {
        if (up[h][l] <= target) {
            sum += upc[h][l];
            l = up[h][l];
        }
    }
    sum += (ll) c[l] * (target-l+1);
    return sum;
}

long long viaggia (int l, int r) {
    // the mature prefix sum part
    int limit = min(r-1, l+k-2);
    ll ans = 0;
    if (r-1 >= limit+1) ans = preopt[r]-preopt[limit+1];
    ans += spm(l, limit);
    return ans;
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
