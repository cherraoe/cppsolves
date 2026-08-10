#include <bits/stdc++.h>
using namespace std;
#define int long long

pair<int,bool> dfs(vector<vector<int>>& personToGroup, vector<vector<int>>& groupToPerson, vector<bool>& didIParseG, vector<bool>& didIParseP, int curr, vector<int>& gc) {
    int v = 0;
    // if (personToGroup[curr].size() > 0 && gc[personToGroup[curr][0]] != -1) {
    //     v = gc[personToGroup[curr][0]];
    bool wegotit = false;
    if (personToGroup[curr].size() > 0) {
        for (int next : personToGroup[curr]) {
            if (gc[next] != -1) {
                wegotit = true;
                v = max(gc[next], v);
            }
        }
    }
    if (!wegotit) {
        v = 1;
        for (int nextgroup : personToGroup[curr]) {
            if (!didIParseG[nextgroup]) {
                didIParseG[nextgroup] = true;
                for (int nextgPerson : groupToPerson[nextgroup]) {
                    if (!didIParseP[nextgPerson]) {
                        didIParseP[nextgPerson] = true;
                        auto sp = dfs(personToGroup, groupToPerson, didIParseG, didIParseP, nextgPerson, gc);
                        if (sp.second) return {sp.first, true};
                        v += sp.first;
                        // cout <<v<<endl;
                    }
                }
            }
        }
        return {v, false};
    }

    return {v, true};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    // precomputing the groups could probably save me a lot of time

    //going to do 3 stages
    // 1 input
    // 2 processing groups
    // 3 using simplified groups

    vector<vector<int>> personToGroup(n+1, vector<int>());
    vector<vector<int>> groupToPerson;

    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        // if (k == 0) { m--; continue; } // getting rid of useless groups
        // if (k == 1) { cin >> k; m--; continue; } // getting rid of useless groups

        vector<int> thisGroup(k);
        for (int j = 0; j < k; j++) {
            cin >> thisGroup[j];
            personToGroup[thisGroup[j]].push_back(i); //  pushing the bvelonging to i group to every person in that group's persontogroup list
        }
        groupToPerson.push_back(thisGroup); //pushing list of people to that group
    }

    vector<int> gc(m, -1);

    vector<bool> didIParseG(m, false);
    vector<bool> didIParseP(n+1, false);
    for (int i = 1; i < n+1; i++) {
        int x;
        bool outercheck = false;
        if (personToGroup[i].size() > 0) {
            for (int next : personToGroup[i]) {
                if (gc[next] != -1) {
                    outercheck = true;
                    x = gc[next];
                }
            }
        }
        if (!outercheck) {
            didIParseP[i] = true;
            // cout << "INSTANCE " << i<<endl;
            pair<int,bool> sp = dfs(personToGroup, groupToPerson, didIParseG, didIParseP, i, gc);
            x = sp.first;
        }

        cout << x << " ";
        if (personToGroup[i].size() > 0) {
            for (int next : personToGroup[i]) {
                gc[next] = x;
            }
        }
    }
}
