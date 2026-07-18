#include <bits/stdc++.h>
using namespace std;

bool cmp(string& a, string& b) { // return 1 if a >= b

    int x = 1; //0 is a, 1 is draw, 2 is b
    for (int i = 0; i < min(a.length(), b.length()); i++) {
        if (a[i] > b[i]) { x = 0; break; }
        if (a[i] < b[i]) { x = 2; break; }
    }

    bool ans = 1;
    if (x == 1) {
        if (a.length() >= b.length()) ans = 1;
        else ans = 0;
    } else {
        if (x == 0) ans = 1;
        else ans = 0;
    }

    return ans;
}

string rev(string x) {
    reverse(x.begin(), x.end());
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];


}
