#include <bits/stdc++.h>
using namespace std;

int fotosintesi(int n, string s) {
    int best = 0;
    map<pair<int, int>, int> abc;
    abc[{0, 0}] = -1;
    int xab = 0, xbc = 0;
    for (int i = 0; i < n; i++) {
        xab += (s[i]=='A') ? 1 : ((s[i]=='C') ? 0 : -1);
        xbc += (s[i]=='B') ? 1 : ((s[i]=='A') ? 0 : -1);
        auto it = abc.find({xab, xbc});
        //ab
        if (it != abc.end()) {
            auto [k, v] = *it;
            best = max(best, i-v);
        } else {
            abc[{xab, xbc}] = i;
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
