#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string in; cin >> in;
    string out;
    for (int i = 0; i < in.length(); i++) {
        if (!(in[i] == 'A' || in[i] == 'O' || in[i] == 'Y' || in[i] == 'E' || in[i] == 'U' || in[i] == 'I' || in[i] == 'a' || in[i] == 'o' || in[i] == 'y' || in[i] == 'e' || in[i] == 'u' || in[i] == 'i')) {
            out.push_back('.');
            if (in[i] < 92) {
                out.push_back(in[i]+32);
            } else {
                out.push_back(in[i]);
            }
        }

    }

    cout << out;
}
