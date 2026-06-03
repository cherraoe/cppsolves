#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s; cin >> s;
    int n; cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(), [&](const auto& a, const auto& b) {
        return x[a] < x[b];
    });
    sort(x.begin(), x.end());

    int completed = 1;

    for (int i = 0; i < n; i++) {
        if (s > x[i]) {
            s += y[idx[i]];
        } else {
            completed = false;
            break;
        }
    }

    if (completed) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
