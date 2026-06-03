#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;

    vector<char> v;

    for (int i = 0; i < n; i++) {
        char inchar; cin >> inchar;
        v.push_back(inchar);
    }

    int c = 0;
    int neg = 1;

    for (int i = 1; i < n; i++) {
        if (v[i] == v[i-neg]) {
            c++;
            neg++;
        } else {
            neg = 1;
        }
    }

    cout << c;
}
