#include <bits/stdc++.h>
using namespace std;

vector<int> verifica(int n, vector<int> t) {
    // first off i need to decide where to start, so ill get the lowest and leftmost(for now) value
    int firstlvindex = 0;
    int lastlvindex = 0;
    int lv = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (t[i] < lv) {
            lv = t[i];
            lastlvindex = i;
            firstlvindex = lastlvindex;
        } else if (t[i] == lv) {
            lastlvindex = i;
        }
    }
    int l = firstlvindex + ((lastlvindex-firstlvindex)/2);
    int r = l;

    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    stable_sort(a.begin(), a.end(), [&](const auto& u, const auto& v){ return t[u] < t[v]; });
    // this sort will sort from beginning to end while
    // for (int i = 0; i < n; i++) cout << a[i] << " ";
    // cout << endl;

    vector<int> build;
    stack<int> s;
    int lx = 0;
    int rx = n-1;
    for (int i = n-1; i > 0; i--) {
        if (t[lx] >= i) {
            s.push(lx);
            lx++;
        } else if (t[rx] >= i) {
            s.push(rx);
            rx--;
        } else {
            break;
        }
    }
    if (lx != rx) return {};
    s.push(lx);
    while (!s.empty()) {build.push_back(s.top()); s.pop();}
    return build;
}
