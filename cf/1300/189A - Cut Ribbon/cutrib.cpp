#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b, c; cin >> n >> a >> b >> c;

    vector<int> r(n, -1);
    if (a <= n) r[a-1] = 1;
    if (b <= n) r[b-1] = 1;
    if (c <= n) r[c-1] = 1;
    for (int i = 0; i < n; i++) {
        if (i >= a && r[i-a]!=-1) r[i] = max(r[i], r[i-a]+1);
        if (i >= b && r[i-b]!=-1) r[i] = max(r[i], r[i-b]+1);
        if (i >= c && r[i-c]!=-1) r[i] = max(r[i], r[i-c]+1);
    }

    cout << r[n-1];
}
