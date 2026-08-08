#include <bits/stdc++.h>
using namespace std;

vector<int> verifica(int n, vector<int> t) {
    vector<int> build;
    stack<int> s;

    int l = 0;
    int r = n-1;
    for (int i = n-1; i > 0; i--) {
        if (t[l] >= i) {
            s.push(l);
            l++;
        } else if (t[r] >= i) {
            s.push(r);
            r--;
        } else {
            break;
        }
    }
    if (l!=r) return {};
    build.push_back(l);
    while (!s.empty()) {
        build.push_back(s.top());
        s.pop();
    }
    return build;
}
