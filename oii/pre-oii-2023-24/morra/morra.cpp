#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> p;
vector<pair<int,int>> t; // first hand, second player id
vector<int> c(3);

pair<int,int> rps(pair<int,int> a, pair<int,int> b) {
    if (a.first == b.first) {
        return a;
    } else {
        if (a.first == 0) { // rock
            return (b.first==1) ? b : a;
        } else if (a.first == 1) { // paper
            return (b.first==2) ? b : a;
        } else { // scissors
            return (b.first==0) ? b : a;
        }
    }
}

void build(int no, int l, int r) {
    if (l == r) {
        t[no] = {
            (s[l]=='S') ? 0 :
            (s[l]=='C') ? 1 : 2
            , p[l]};
        c[t[no].first]++;
        return;
    }

    int m = (l+r)/2;
    build(2*no, l, m);
    build(2*no+1, m+1, r);
    t[no] = rps(t[2*no], t[2*no+1]);
}

bool update(int no, int l, int r, int hand, int pid) {
    if (l == r && t[no].second==pid) {
        c[t[no].first]--;
        t[no] = {hand, pid};
        c[t[no].first]++;
        return true;
    } else if (l == r) return false;
    int m = (l+r)/2;
    bool bla1 = update(2*no, l, m, hand, pid);
    bool bla2 = false;
    if (!bla1) bla2 = update(2*no+1, m+1, r, hand, pid);
    t[no] = rps(t[2*no], t[2*no+1]);
    return bla1 || bla2;
}

//problem
void init(int K, string S, vector<int> P) {
    n = (1 << K);
    s = S;
    p = P;
    t.assign(4*(1 << K), {0, 0});

    // 0 rock S
    // 1 paper C
    // 2 scissors F
    build(1, 0, n-1);
}

variant<bool, pair<int, int>> imbroglia(int X, char C) {
    int thehand = (C=='S') ? 0 : ((C=='C') ? 1 : 2);
    update(1, 0, n-1, thehand, X);
    if (t[1].second == 0) return true;
    return false;
    return make_pair(42, 69);
}
