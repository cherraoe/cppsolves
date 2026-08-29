#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long

vector<int> cucina(int N, int K, int X, vector<int> H) {
    // n is number of contestants
    // k is the max queue length
    // x is the HARD limit
    // h is each contestant arrival time
    unordered_map<int, int> h;
    for (int i = 0; i < N; i++) {
        h[H[i]]++;
    }
    vector<int> r(X);
    vector<bool> served(X, false);
    int serv = 0;
    for (int t = X-1; t >= 0; t--) {
        int ti = t;
        int q = min(K, h[ti]);
        while (q > 0 && !served[ti] && ti < X) {
            served[ti] = true;
            serv++;
            q--;
            ti++;
        }
        r[t] = serv;
    }
    return r;
}
