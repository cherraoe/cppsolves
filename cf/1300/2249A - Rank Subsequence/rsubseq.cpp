#include <bits/stdc++.h>
using namespace std;

// one indexing everything even tho im not used to it, wish me luck

bool is_valid(int l, int r, int u, int v, int j, int m) {
    bool leftok = !(j >= l && j <= r);
    int mj = (m-j)+1;
    bool rightok = !(mj >= u && mj <= v);
    // cout<<"is "<<j<<" "<<l<<"-"<<r<<" & "<<mj<<" in "<<u<<"-"<<v<<"  |  "<<leftok<<" "<<rightok<<endl;
    return leftok && rightok;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        n++; vector<int> l(n), r(n), u(n), v(n); n--;
        for (int i = 1; i <= n; i++) {
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        }

        // if (t != 3)continue;

        int m = n+1;
        int yay = 0;

        for (int i = 1; i <= n; i++) {
            if (is_valid(l[i], r[i], u[i], v[i], i, m)) {
                yay++;
            } else {
                m--;
                i = 1;
                yay = 0;
                // cout << "deleted " << i << endl;
            }
        }
        cout << yay << endl;
    }
}
