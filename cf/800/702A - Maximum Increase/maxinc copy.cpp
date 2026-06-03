#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c = 1, tc = 1; cin >> n;
    vector<int> a(n); cin >> a[0];

    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] > a[i-1]) {
            tc++;
            c = max(c, tc);
        } else {
            tc = 1;
        }
    }

    cout << c;
}
