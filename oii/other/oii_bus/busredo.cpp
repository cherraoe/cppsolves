#include <bits/stdc++.h>
#include <queue>
using namespace std;

int pianifica(int n, int l, vector<vector<int>> fs) {

    // i have
    // n = number of stops
    // l = number of lines
    // fs = line > its stops

    // sf = stop > its lines
    // and the forementioned map

    // changes counter, stop id
    queue<tuple<int,int>> q;                                                          // queue

    map<pair<int,int>, int> mp;                                                           // map of 1st

    vector<int> univ(n, -1);                                                       // best value
    vector<vector<bool>> fresh;                                                        //fresh/visitd
    vector<vector<int>> sf(n);                                                            //stop to line
    for (int li = 0; li < l; li++) {
        int fsize = fs[li].size();
        fresh.push_back(vector<bool>(fsize, true));
        // cout <<"initf["<<li<<"]s="<<fsize<<endl;
        for (int j = 0; j < fsize; j++) {
            if (mp[{li, fs[li][j]}] == 0) mp[{li, fs[li][j]}] = j+1;
            sf[(fs[li][j])].push_back(li);
            // cout << "sf["<<fs[li][j]<<"] += "<<li<<"\n";
        }
    }

    // need to find the earliest occurence of that stop number, i could lowkey just store it in a map
    // did that

    // bfs
    q.push({0, 0});
    while (!q.empty()) {
        auto [cc, cu] = q.front(); q.pop();

        for (auto nxg : sf[cu]) {
            // cout << "nxg " << nxg<<"\n";

            int si = mp[{nxg, cu}]; // stop index of the first one SI
            // cout <<"si = " <<si << "\n";
            int sil = fresh[nxg].size();
            // cout <<"sil = " <<sil << "\n";

            while (si < sil && fresh[nxg][si]) {
                int target = fs[nxg][si];
                fresh[nxg][si] = false;
                if (univ[target]==-1) {
                    univ[target] = cc;
                    // cout << "wrote u[" << cu << "]= " << cc << "\n";

                    q.push({cc+1, target});
                    // cout << "pushed {"<<cc+1<<", "<< target<<"}\n";
                }

                si++;
            }
        }
    }

    return univ[n-1];
}
