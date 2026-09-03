#include <bits/stdc++.h>
using namespace std;

int machete(int n, int k, vector<int> p) {
    // n number of nodes
    // k limit
    // p holds the index of parent node
    //
    // computing for lowest number of removals
    vector<int> sub(n, 1); //subtree size including itself
    vector<int> d(n, 1);
    vector<int> l(n, 1);
    for (int i = n-1; i > 0; i--) {
        sub[p[i]] += sub[i];
    }
    for (int i = 1; i < n; i++) {
        d[i] = d[p[i]]+1;
    }
    for (int i = n-1; i > 0; i--) {
        l[p[i]] = max(l[p[i]], l[i]+1);
    }
    int cuts = 0;
    bool fs = true;
    int it = 1;
    int pick = 0;
    int bonus = 0;
    while (true) {
        if (it >= n) {
            if (!fs || pick == 0) break;
            cuts++;
            cout << "cut p[" << pick << "]=0\n";
            p[pick] = 0;

            sub.assign(n, 1);
            d.assign(n, 1);
            l.assign(n, 1);
            for (int i = n-1; i > 0; i--) {
                sub[p[i]] += sub[i];
            }
            for (int i = 1; i < n; i++) {
                d[i] = d[p[i]]+1;
            }
            for (int i = n-1; i > 0; i--) {
                l[p[i]] = max(l[p[i]], l[i]+1);
            }

            pick = 0;
            bonus = 0;
            it = 1;
            fs = false;
        }
        // cout << d[i] << "+" << l[i]<<"-1="<<d[i]+l[i]-1<<" > "<< k<<"\n";
        if (d[it]+l[it]-1 > k) {
            // cout << bonus << " <= " << sub[i]<<"-"<<l[i]<<"="<<sub[i]-l[i]<< "  &&  " << d[i] <<" > "<< d[pick] << "\n";
            if (bonus <= sub[it]-l[it] && d[it] <= d[pick] && d[it] <=k+1) {
                bonus = sub[it]-l[it];
                pick = it;
                fs = true;
            }
        }
        it++;
    }
    return cuts;
}


// GRADER DI ESEMPIO, NON MODIFICARE

#ifndef EVAL

int main() {

    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    for(auto &i : P) cin >> i;

    cout << machete(N, K, P) << endl;
}
#endif
