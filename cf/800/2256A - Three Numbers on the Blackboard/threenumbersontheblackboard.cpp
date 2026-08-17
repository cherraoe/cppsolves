#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        vector<int> a(3);
        for (int i = 0; i < 3; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int b = abs(a[2]-a[0]);
        int c = abs((a[0]+a[1])-a[0]);
        cout << min(b, c) << endl;
    }
}
