#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;
#define ll long long

vector<int> assegna(int n, int m, vector<vector<int>> s) {

    bool sub2 = true;
    for (int i = 0; i < n; i++) {
        if (s[i].size() > 1) sub2 = false;
    }

    vector<int> ans(m, -1);
    if (sub2) {
        vector<bool> mp(m);
        vector<int> relevant;

        bool nothing = false;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            bool temp = true;
            for (int x : s[i]) {
                temp = false;
                if (nothing) return {};
                // real

                if (mp[x] && prev != x) return {};

                if (!mp[x]) relevant.push_back(x);
                mp[x] = true;
                prev = x;
            }
            nothing = temp;

        }

        int exp = m-1;
        for (int x : relevant) {
            ans[x] = exp;
            exp--;
        }
        for (int i = 0; i < m; i++) {
            if (ans[i] == -1) {
                ans[i] = exp;
                exp--;
            }
        }

        // ans[subtask of the first] = exponent-1 then descending

    } else {
        // n participants
        // m subtasks
        // s[participant] = subtasks they solved

        // since the biggest values are the most important ones i should assign those first
        // by looking for subtasks where theres a clean break point of one side having it and the other not having it (initial hypothesis, gonna brute to see)
        vector<vector<bool>> c(n, vector<bool>(m, false));
        for (int p = 0; p < n; p++) {
            for (int sub : s[p]) {
                c[p][sub] = true;
            }
        }

        vector<bool> fresh(m, true);
        vector<pair<int,int>> g;
        g.push_back({0, n-1});

        for (int i = m-1; i >= 0; i--) {

            int ssub = -1; // whether i can split it

            for (int si = 0; si < m && ssub == -1; si++) { // going through each subtask
                if (!fresh[si]) continue;

                bool tgv = true; // this group valid ?

                // can i split all groups using this sub as ref?
                for (auto [l, r] : g) {
                    bool cut = false;
                    for (; l <= r; l++) {
                        if (!c[l][si] && !cut) cut = true;
                        if (c[l][si] && cut) {
                            tgv = false; // if i cant
                            break;
                        }
                    }
                    if (!tgv) break;
                }

                if (tgv) ssub = si;
            }

            if (ssub != -1) {
                vector<pair<int,int>> ng;
                for (auto [l, r] : g) {
                    int mid = l;
                    while (mid <= r && c[mid][ssub]) mid++;

                    if (mid == r+1 || mid == l) {
                        ng.push_back({l, r});
                    } else {
                        ng.push_back({l, mid-1});
                        ng.push_back({mid, r});
                    }
                }
                g = ng;

                ans[ssub] = i;
                fresh[ssub] = false;
            } else { // if cant split
                return {};
            }
        }
        // every iteration need to get the largest clean group, and then use it to break into ranges
        // then every it after that needs to get the largest group thats valid across all ranges
    }

    return ans;
}
