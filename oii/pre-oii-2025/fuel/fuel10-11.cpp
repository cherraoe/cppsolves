#include <bits/stdc++.h>
using namespace std;
#define ll long long

int LOG;
int n, k;
vector<int> c;
vector<vector<int>> upnode;
vector<vector<ll>> upcost;
vector<ll> prefwin;

void pianifica(int N, int K, vector<int> C) {
    n = N; k = K; c = C;

    while ((1 << LOG) < n) {
        LOG++;
    }

    vector<int> nxt(n, n); //pointing to right beyond end because condition is NEXT smaller
    stack<int> st;
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && c[st.top()] >= c[i]) st.pop();
        if (!st.empty()) nxt[i] = st.top();
        st.push(i);
    }

    upnode.assign(LOG, vector<int>(n+1, n));
    upcost.assign(LOG, vector<ll>(n+1, 0));
    upnode[0] = nxt;
    for (int i = 0; i < n; i++) {
        upcost[0][i] = (ll) c[i]* (nxt[i]-i); // ll casting for safety, gets price to next cheapest
    }

    for (int l = 1; l < LOG; l++) {
        for (int i = 0; i < n; i++) {
            int midpoint = upnode[l-1][i];
            upnode[l][i] = upnode[l-1][midpoint];
            upcost[l][i] = upcost[l-1][i] + upcost[l-1][midpoint];
            // building the higher levels using the mid points referred to by the lower level at the same index
        }
    }

    vector<int> win(n);
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() < i-k+1) {
            dq.pop_front();
        } // this forces it to stay in the k range.
        while (!dq.empty() && c[dq.back()] >= c[i]) {
            dq.pop_back();
        } //
        dq.push_back(i);
        win[i] = c[dq.front()];
    } // gives the cost for jumps

    prefwin.assign(n+1, 0);
    for (int i = 0; i < n; i++) {
        prefwin[i+1] = prefwin[i] + win[i];
    } // prefix sum of jump costs for binary lift coord range calculation
    // that was a lie
}

ll spm(int l, int target) {
    if (l > target) return 0;
    int cur = l;
    ll tot = 0;
    for (int li = LOG-1; li >= 0; li--) {
        if (upnode[li][cur] <= target) {
            tot += upcost[li][cur];
            cur = upnode[li][cur];
        }
    }
    tot += (ll) c[cur] * (target-cur+1);
    return tot;
    // i need to trace this whole thing
}

ll viaggia(int l, int r) {
    int limit = min(r-1, l+k-2); // oh so r-1 is just for safety, in case of oddly small queries with big k. i understand l+k but why specifically -2 ? is it bcs the mature part is k-1 and it has to be offset by 1.? in that case, why is the mature offset by -1 specifically? for the prefix sum?
    // oh yeah mature part is l+k-1 cus it has to include the current station. oops
    ll ans = spm(l, limit);
    if (r-1 >= l+k-1) {
        ans += prefwin[r] - prefwin[l+k-1];
    }
    return ans;
}

//grader di prova
#ifndef EVAL
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    vector<int> C(N);
    for (int &x : C) cin >> x;
    pianifica(N, K, C);

    int Q;
    if (!(cin >> Q)) return 0;

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << viaggia(l, r) << "\n";
    }
    return 0;
}
#endif
