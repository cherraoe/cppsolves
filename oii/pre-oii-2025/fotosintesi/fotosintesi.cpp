#include <bits/stdc++.h>
using namespace std;

int fotosintesi(int n, string s) {
    int t = n/3;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++) {
        if (s[i]=='A') a++;
        else if (s[i]=='B') b++;
        else c++;
    }
    int ans = n;
    int l = 0, r = n-1;
    while (ans > 0) {
        cout << "l="<<l<<" r="<<r<<"\n";
        if (a == b  && b == c) return ans;
        int& first = (s[l]=='A') ? a : ((s[l]=='B') ? b : c);
        int& second = (s[r]=='A') ? a : ((s[r]=='B') ? b : c);
        if (first > second) {
            l++;
            first--;
        } else {
            r--;
            second--;
        }
        ans--;
    }
    return ans;
}

// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL
int main () {
    string S; cin >> S;

    cout << fotosintesi(S.size(), S) << endl;
}
#endif
