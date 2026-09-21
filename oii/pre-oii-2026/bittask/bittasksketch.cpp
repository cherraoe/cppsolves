#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> assegna(int n, int m, vector<vector<int>> s) {
    // n participants
    // m subtasks
    // s[participant] = subtasks they solved

    // since the biggest values are the most important ones i should assign those first
    // by looking for subtasks where theres a clean break point of one side having it and the other not having it (initial hypothesis, gonna brute to see)
    vector<vector<bool>> c(n, vector<bool>(m, false));
    for (int x = 0; x < n; x++) {
        for (int y : s[x]) {
            c[x][y] = true;
        }
    }

    vector<int> p(m, 0);
    vector<bool> fresh(m, true);
    int speciallimit = n;
    for (int i = m-1; i >= 0; i--) { // loops once per subtask

        int lss = -1; // largest subtask size
        int ls = -1; // largest subtask

        for (int si = 0; si < m; si++) { // checks all subs
            if (!fresh[si]) continue;

            int tss = 0; //this subtask size
            bool cut = false;

            for (int pi = 0; pi < speciallimit; pi++) { // looping through relevant participants
                if (!c[pi][si] && pi == 0) break; // breaks if 0
                if (!c[pi][si] && !cut) cut = true; // acknowledges cut
                if (c[pi][si] && cut) {
                    tss = -1;
                    break; // breaks if already cut and found true
                }
                if (c[pi][si]) tss++; // increases while normal
            } // pi

            if (tss > lss) {
                lss = tss;
                ls = si;
                // cout << "ls=si="<<si<<" lss="<<lss<<"\n";
            }
        } // si

        if (ls != -1) {
            // cout <<"W) sl="<<speciallimit<<">"<<lss<<" p["<<ls<<"]="<<i<<"\n";
            speciallimit = lss;
            p[ls] = i;
            fresh[ls] = false;
        } else { // if broken i guess (?) unsure if this works
            return {0};
        }
    } // i
    return p;
}
