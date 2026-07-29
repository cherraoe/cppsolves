#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, k; cin >> n >> k;
        vector<int> a(n), h(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> h[i];

        // if (t != 2) continue;

        // need to calculate best length thats still under fruit limit k
        // subseq has have its heights divisible by the next
        // first try, bad complexity with instant optimisations when conditions bad
        int bl = 0; // to prune already worse setups
        int tempk = 0;
        int l = 0, r = 0;
        while (l < n && r < n) {
            //will try bl of self, not next
            // will check if can do next, or else it will stop backtracking
            // cout << "check " << (tempk+a[r]) << " <= " << k << endl;

            if (l > r) {
                // cout << "anew\n";
                // else try anew
                tempk = 0;
                r = l;
                continue;
            }
            if (tempk+a[r] <= k) { //check if current is valid
                // cout << "wrote on l" << l << " r" << r << " tempk" << tempk << " ar" << a[r]<< endl;
                bl = max(bl, (r-l)+1);
                // above line doesnt check, its fine since i only need to check % when going forward

                // if (r+1 < n) cout << "%" << ((h[r] % h[r+1])) << endl;

                if (r+1 >= n) {
                    r++;
                    break;
                } else if ((h[r] % h[r+1]) == 0) {
                    // cout << "continued\n";
                    tempk += a[r];
                    r++;
                    continue;
                } else {
                    // cout << "anew\n";
                    // else try anew
                    l = r+1;
                    tempk = 0;
                    r = l;
                }

            } else { // fruit limit hit, reset
                // cout << "flhr\n";
                tempk -= a[l];
                l++;
                continue;
            }


        }

        cout << bl << endl;
    } // end tc
}
