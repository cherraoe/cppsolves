#include <vector>

using namespace std;

int rimembra (int n, int k, vector<int> v) {
    int best = 0;
    int l = 0, r = 0;
    int ku = 0;
    for (int i = 0; i < n; i++) {
        // cout << "v["<<i<<"]="<<v[r]<<"\t";
        if (!v[r]) { //if r has a price
            if (ku >= k) { //if i cant
                while (ku >= k) { //i roll back until ku is smaller than k
                    if (!v[l]) {
                        ku--; // if it was == 0, i can gain 1
                        // cout << "undid, ku=" << ku <<"\t";
                    }
                    l++; // i bring it ahead
                }
            }
            ku++; // i just take it
            // cout << "paid, ku="<< ku <<"\t";
        }
        // cout << "  l="<<l<<" r="<<r<<"";
        best = max(best, r-l+1);
        r++;
        // cout <<"\tbest="<<best<< "\n";
    }
    return best;
}
