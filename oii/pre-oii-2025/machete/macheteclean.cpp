#include <bits/stdc++.h>
using namespace std;

int machete(int n, int k, vector<int> p) {
    // n number of nodes
    // k limit
    // p holds the index of parent node

    vector<int> d(n, 1);
    vector<int> h(n, 1);
    for (int i = 1; i < n; i++) {
        d[i] = d[p[i]]+1;
    }
    for (int i = n-1; i > 0; i--) {
        h[p[i]] = max(h[p[i]], h[i]+1);
    }

    int ans = 0;
    for (int j = 1; j < n; j++) {
        if (h[j]+d[j]-1 > k) {
            if (h[j]+1 <= k) {
                ans++;
                p[j] = 0;
                // cout << "cut p["<<j<<"]=0\n";
                j = 1;


                d.assign(n, 1);
                h.assign(n, 1);
                for (int i = 1; i < n; i++) {
                    d[i] = d[p[i]]+1;
                }
                for (int i = n-1; i > 0; i--) {
                    h[p[i]] = max(h[p[i]], h[i]+1);
                }
            }
        }
    }
    return ans;
}


// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(auto &i : P) cin >> i;

    cout << machete(N, K, P) << endl;
}
#endif
