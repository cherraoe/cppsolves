#include <bits/stdc++.h>
using namespace std;

int fotosintesi(int n, string s) {
    map<pair<int,int>, int> mp;
    mp[{0,0}] = -1;
    int best = 0;
    int ab = 0;
    int bc = 0;
    for (int i = 0; i < n; i++) {
        ab += (s[i]=='A') ? 1 : ((s[i]=='B') ? -1 : 0);
        bc += (s[i]=='B') ? 1 : ((s[i]=='C') ? -1 : 0);
        auto it = mp.find({ab, bc});
        if (it != mp.end()) {
            best = max(best, i-it->second);
        } else {
            mp[{ab, bc}] = i;
        }
    }
    return best;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL
int main () {
    string S; cin >> S;

    cout << fotosintesi(S.size(), S) << endl;
}
#endif
