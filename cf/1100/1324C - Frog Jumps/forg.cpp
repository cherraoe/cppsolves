#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s; cin >> s;
        vector<bool> fresh(s.size(), 1);
        int best = 1;

        int temp = 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                temp++;
            } else {
                best = max(best, temp);
                temp = 1;
            }
        }
        best = max(best, temp);

        cout << best << endl;
    }
}
