#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;

        int n = s.size();
        int l = 0, r = 0;

        int b = '-';
        int bi = l;

        auto bubl = [&]() {
            for (int i = bi; i > l; i--) {
                s[i]--;
                swap(s[i], s[i-1]);
            }
        };

        while (l < n) {
            if (b == '-') b = s[l];
            if (b < s[r]-(r-l)) {
                b = s[r]-(r-l);
                bi = r;
            }

            if (r+1 >= n || r-l > 9) {
                bubl();
                b = '-';
                bi = l;
                l++;
                r = l;
            }
            r++;
        }

        cout << s << endl;
    }
}
