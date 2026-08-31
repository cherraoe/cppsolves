#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
    }

    // ill draft a brute force that ill then optimise
    // i cant store the exact indices cus then the array will be too big, i can however store the ranks and reference l and r using two pointers
    vector<int> lc = l, rc = r;
    sort(lc.begin(), lc.end());
    sort(rc.begin(), rc.end());
    // then check the if satisfied after calculations
    // and if broken, then c++ and end segment
    // and if true, continue segment
    vector<pair<int,int>> ans;
    // i really hope ignoring l and r pairs and only keeping the pure height works
    int h = 1;
    int li = 0, ri = 0;
    int begin = 1e10;
    int end = -1e10;
    int run = true;
    while (run && (li < n || ri < n)) {


        if (begin == 1e10 && h >= k) {
            begin = lc[li];
            end = 1e10;
            // cout << "lc["<<li<<"]="<<lc[li]<<" rc["<<ri<<"]="<<rc[ri]<<" h="<<h<<" begin="<<begin<<" begin\n";
        }

        while (ri < n && rc[ri] < (li+1 < n ? lc[li+1] : 1e9)) {
            // cout << "lc["<<li<<"]="<<lc[li]<<" rc["<<ri<<"]="<<rc[ri]<<" h="<<h<<" begin="<<begin<<" --ing\n";
            h--;
            ri++;
            if (end == 1e10 && h < k) {
                end = rc[ri-1];
                // cout << end <<" assigned end\n";
            }
            // cout << "lc["<<li<<"]="<<lc[li]<<" rc["<<ri<<"]="<<rc[ri]<<" h="<<h<<" begin="<<begin<<" --ed\n";
        }

        if (begin != 1e10 && end != 1e10) {
            // cout << "lc["<<li<<"]="<<lc[li]<<" rc["<<ri<<"]="<<rc[ri]<<" h="<<h<<" begin="<<begin<<" pushing\n";
            ans.push_back({begin, end});
            begin = 1e10;
            end = -1e10;
            // cout << "lc["<<li<<"]="<<lc[li]<<" rc["<<ri<<"]="<<rc[ri]<<" h="<<h<<" begin="<<begin<<" pushed\n";
        }

        if (li < n) {
            li++;
            h++;
            // cout << "lc["<<li<<"]="<<lc[li]<<" rc["<<ri<<"]="<<rc[ri]<<" h="<<h<<" begin="<<begin<<" ++\n";
        } else {
            run = false;
        }

    }
    cout << ans.size() << "\n";
    for (auto [first, second] : ans) cout << first << " " << second << endl;
}
