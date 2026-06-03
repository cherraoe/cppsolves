#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c = 1, tc = 1; cin >> n;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            tc++;
            c = max(c, tc);
        } else {
            tc = 1;
        }
    }

    cout << c;
}
