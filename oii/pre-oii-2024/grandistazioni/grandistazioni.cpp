#include <bits/stdc++.h>
#include <climits>
#include <queue>
using namespace std;
#define ll long long

ll viaggia(int n, int m, vector<int> a, vector<int> b, vector<int> t, vector<int> v, vector<int> w) {
    // n nodes
    // m edges
    // a root, b destination, t time
    // v is first time error destination for that a (same i)
    // w is the time of the error route

    // old approach was wrong, i need to reverse compute the best solution, and then retrace it on each step while missing it when needed
    vector<ll> ideal(n, LLONG_MAX);
    ideal[n-1] = 0;
    vector<vector<tuple<int,int>>> adj(n); // station a has destination b with time t
    vector<vector<tuple<int,int>>> inverse(n); // station b has sources a with time t
    for (int i = 0; i < m; i++) {
        adj[a[i]].push_back({b[i],t[i]});
        inverse[b[i]].push_back({a[i],t[i]});
    }
    priority_queue<tuple<ll,int>, vector<tuple<ll,int>>, greater<>> iq;
    iq.push({0, n-1});
    while (!iq.empty()) {
        auto [time, st] = iq.top(); iq.pop();
        if (ideal[st] < time) continue;
        for (auto [source, travel] : inverse[st]) {
            if (ideal[source] < time+travel) continue;
            ideal[source] = time+travel;
            iq.push({time+travel, source});
        }
    }


    priority_queue<tuple<ll,int>, vector<tuple<ll,int>>, greater<>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [time, st] = pq.top(); pq.pop();
        if (st == n-1) return time;
        if (v[st] != -1) {
            pq.push({time+w[st], v[st]});
            v[st] = -1;
            // cout << "Wushed "<<time<<"+"<<w[st]<<"="<<time+w[st]<<", "<<v[st]<<"\n";
        } else {

            int pst = -1;
            int ptrav;
            for (auto [dst, travel] : adj[st]) {
                if (pst == -1) {
                    pst = dst;
                    ptrav = travel;
                } else {
                    if (ideal[pst]+ptrav > ideal[dst]+travel) {
                        pst = dst;
                        ptrav = travel;
                    }
                }
            }
            // if (ref[pst] > time+ptrav) {
            //     ref[pst] = time+ptrav;
                pq.push({time+ptrav, pst});
            // }
            // cout << "pushed "<<time<<"+"<<ptrav<<"="<<time+ptrav<<", "<<pst<<"\n";
        }
    }
    return -20;
}
