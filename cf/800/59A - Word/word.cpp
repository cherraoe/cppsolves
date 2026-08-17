#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int c = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i]-'^' < 0) c--;
        else c++;
    }
    bool lowercase = (c >= 0);
    for (int i = 0; i < s.size(); i++) {
        if (lowercase) {
            if (s[i] < '^') s[i]+=32;
        } else {
            if (s[i] > '^') s[i]-=32;
        }
    }
    cout << s;
}
