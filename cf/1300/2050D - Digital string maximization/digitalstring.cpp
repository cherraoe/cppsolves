#include <bits/stdc++.h>
#include <pthread.h>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;

        int n = s.size();

        int l = 0, r = 0;
        // while (l < n) {
        //     if (s[l] < s[r]-(r-l)) {
        //         s[r]-= r-l;
        //         swap(s[l], s[r]);
        //         l++;
        //         continue;
        //     }
        //     if (r+1 < n) {
        //         r++;
        //         continue;
        //     }
        //     if (r-l > 10) {
        //         l++;
        //         continue;
        //     }
        //     l++;
        // } this only does one pass, doesnt work correctly, fetches first valid option, not best


        while (l < n) { // goal of this it to loop through ten each time and get the best
            char bsf = '-';
            int bsfi = l;
            if (r >= n) {
                if (bsf != '-') {
                    // swap(s[l], s[bsfi]);
                    for (int i = bsfi; i > l; i--) { s[i]--; swap(s[i], s[i-1]); }
                    cout<<"N ";
                }
                l++;
                r=l+1;
                cout<<"n ";
                continue;
            } // past n boundary
            if (r-l > 9) {
                if (bsf != '-') {
                    // swap(s[l], s[bsfi]);
                    for (int i = bsfi; i > l; i--) { s[i]--; swap(s[i], s[i-1]); }
                    cout<<"V ";
                }
                l++;
                r=l+1;
                cout<<"v ";
                continue;
            } // past limit based on value, should handle 10 limit


            if (s[r]-(r-l) > bsf) { // save if better
                bsf = s[r]-(r-l);
                bsfi = r;
            }
            r++;
        }

        cout << s << endl;
    }
}
