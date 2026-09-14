#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll acquista (int n, int m, int l, vector<int> x, vector<int> t) {
    sort(x.begin(), x.end());
    multiset<int> h;
    for (int ins : t) h.insert(ins);
    ll ans = 0;
    for (int i = n-1; i >= 0 && !h.empty(); i--) {
        auto c = h.lower_bound(x[i]);
        if (c != h.end() && *c < x[i]+l) {
            ans += l - min(l, *c-x[i]);
            h.erase(c);
        }
    }
    return ans;
}
