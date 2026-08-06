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

bool is_arr_valid(vector<int>& l, vector<int>& r, vector<int>& u, vector<int>& v, int m, int n) {
    int j = 1;
    for (int i = 1; i <= n; i++) {
        if (is_valid(l[i], r[i], u[i], v[i], j, m)) {
            j++;
        }
    }
    if (j > m) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n; cin >> n;
        n++;
        vector<int> l(n), r(n), u(n), v(n);
        n--;
        for (int i = 1; i <= n; i++) cin >> l[i] >> r[i] >> u[i] >> v[i];

        int highestvalid = 0;

        // int lp = 1, rp = n, mid;
        // while (lp < rp) {
        //     mid = lp+((rp-lp)/2);
        //     if (is_arr_valid(l, r, u, v, mid, n)) {
        //         lp = mid+1;
        //         highestvalid = mid;
        //     } else {
        //         rp = mid-1;
        //     }
        // }
        for (int i = n; i > 0; i--) {
            if (is_arr_valid(l, r, u, v, i, n)) {
                highestvalid = i;
                break;
            }
        }

        cout << highestvalid << endl;
    }
}
