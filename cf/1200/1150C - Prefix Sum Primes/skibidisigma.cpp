#include <bits/stdc++.h>
using namespace std;

bool pri(int c) {
    if (c == 1) return false;
    for (int i = 2; i*i <= c; i++) {
        if (c%i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n; cin >> n;
    int u = 0, e = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x-1) {
            e++;
        } else {
            u++;
        }
    }

    int c = 0;

    while (u > 0 || e > 0) {
        if (u > 0 && e > 0) {
            if (pri(c+1)) {
                cout << "1 ";
                u--;
                c++;
            } else {
                cout << "2 ";
                e--;
                c += 2;
            }
        } else if (u > 1) {
            cout << "1 1 ";
            u -= 2;
            c += 2;
        } else {
            if (e > 0) {
                cout << "2 ";
                e--;
                c += 2;
            } else {
                cout << "1 ";
                u--;
                c++;
            }
        }
    }
    // end
}
