#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int pianifica(int n, int l, vector<vector<int>> f) {

    vector<vector<int>> stl(n);
    vector<vector<int>> lts;
    vector<vector<bool>> vls;
    vector<unordered_map<int, int>> lte;

    for (int i = 0; i < l; i++) {
        vector<int> thislts;
        unordered_map<int, int> thisE;
        int c = 0;
        for (int x : f[i]) {
            stl[x].push_back(i);
            thislts.push_back(x);
            if (!thisE.count(x)) thisE[x] = c;
            c++;
        }
        lts.push_back(thislts);
        lte.push_back(thisE);
        vls.push_back(vector<bool>(thislts.size(), false));
    }

    vector<bool> vs(n, false);
    vector<int> ans(n, INT_MAX);
    queue<tuple<int,int>> q;


    vs[0] = true;
    ans[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [cu, de] = q.front(); q.pop();

        for (int nl : stl[cu]) {

            bool foundcu = false;
            int hi = lte[nl][cu];
            for (int i = hi; i < lts[nl].size(); i++) {

                if (vls[nl][i]) break;

                int ns = lts[nl][i];
                if (foundcu || ns == cu) {
                    if (ns == cu) foundcu = true;
                    vls[nl][i] = true;
                    if (vs[ns]) continue;
                    vs[ns] = true;

                    if (ns == n-1) return de;
                    if (ans[ns] > de) ans[ns] = de;
                    q.push({ns, de+1});
                    // cout <<"pushed station" << ns << " depth" << de+1 << "\n";
                }
            }
        }
    }
    int out = -1;
    if (ans[n-1] != INT_MAX) out = ans[n-1];
    return out;
}
