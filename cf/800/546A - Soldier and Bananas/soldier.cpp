#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, n, w; cin >> k >> n >> w;
    int min = 0;
    int c = 0;
    for (int i = 1; i <= w; i++) {
        c += k*i;
        if (c > n) min = c-n;
    }

    cout << min;
}
