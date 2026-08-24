#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int best = -1;
    vector<int> bestarr(n);
    for (int i = 0; i < n; i++) {

        // vector<int> asc(n, -1); // ascending ideal left to right with references to closest smaller value
        // stack<int> st;
        // for (int i = 0; i < n; i++) {
        //     while (!st.empty() && a[st.top()] > a[i]) {
        //         st.pop();
        //     }
        //     if (!st.empty()) {
        //         asc[i] = st.top();
        //     }
        //     st.push(i);
        // }
        // while (!st.empty()) st.pop();
        // vector<int> des(n, n); // descending left to right with references to closest
        // for (int i = n-1; i >= 0; i--) {
        //     while (!st.empty() && a[st.top()] > a[i]) {
        //         st.pop();
        //     }
        //     if (!st.empty()) {
        //         des[i] = st.top();
        //     }
        //     st.push(i);
        // }


        int localsum = 0;
        vector<int> localarr(n);

        localsum -= a[i];
        // localarr[i] = a[i];
        int l = i, r = i;

        int prevl = a[i];
        while (l >= 0) {
            if (a[l] < prevl) {
                prevl = a[l];
            }
            localsum += prevl;
            localarr[l] = prevl;

            l--;
        }

        int prevr = a[i];
        while (r < n) {
            if (a[r] < prevr) {
                prevr = a[r];
            }
            localsum += prevr;
            localarr[r] = prevr;

            r++;
        }

        if (best < localsum) {
            best = localsum;
            bestarr = localarr;
        }
    }
    for (int x : bestarr) cout << x << " ";
}
