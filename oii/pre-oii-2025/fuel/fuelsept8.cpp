#include <bits/stdc++.h>
#include <queue>
#include <stack>
using namespace std;
#define ll long long

int n, k;
vector<int> c;
vector<int> mnt;
vector<int> p;

void pianifica (int N, int K, vector<int> C) {
    n = N; k = K;
    c = C;
    mnt.assign(n, -1);
    p = c;
    stack<int> st;
    // store index
    for (int i = n-1; i >= 0; i--) {
        // clear larger elements than current
        while (!st.empty() && c[st.top()] >= c[i]) {
            st.pop();
        }
        // if not empty and if valid then set
        if (!st.empty() && st.top() <= i+k) {
            mnt[i] = st.top();
            p[i] = c[i]*(st.top()-i);
        } else {
            mnt[i] = i+1;
        }

        st.push(i);
    }

    cout << "mnt: ";
    for (int m : mnt) cout << m << " ";
    cout << "\np: ";
    for (int m : p) cout << m << " ";
    cout << "\n";
}

long long viaggia (int l, int r) {
    ll ans = 0;
    while (l < r) {
        if (mnt[l] > r || mnt[l] == -1) {
            ans += c[l]*(r-l);
            l = r;
        } else {
            ans += p[l];
            l = mnt[l];
        }
    }
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
