#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    vector<int> posab;
    vector<int> posba;
    int n = s.size();
    for (int i = 0; i < n-1; i++) {
        if (s[i] == 'A' && s[i+1] == 'B') {
            posab.push_back(i);
        }
        if (s[i] == 'B' && s[i+1] == 'A') {
            posba.push_back(i);
        }
    }

    bool ans = false;
    for (int x : posab) {
        for (int y : posba) {
            if (x > y+1 || x < y-1) {
                ans = true;
                break;
            }
        }
    }
    cout << ((ans) ? "YES" : "NO");
}
