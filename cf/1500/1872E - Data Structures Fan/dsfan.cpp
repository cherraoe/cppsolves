#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;
vector<int> a;
vector<bool> lz, b;

// if s is on leaf, stands for type,
// if on any parent, stands for mixed or no

void build(int node, int l, int r) {
    if (l == r) {
        t[b[l]][node] = a[l];
        t[!b[l]][node] = 0;
        return;
    }
    int mid = l+(r-l)/2;
    build(2*node, l, mid);
    build(2*node+1, mid+1, r);
    t[0][node] = t[0][2*node] ^ t[0][2*node+1];
    t[1][node] = t[1][2*node] ^ t[1][2*node+1];
}

void apply(int node, int l, int r) {
    swap(t[0][node], t[1][node]);
    lz[node] = !lz[node];
}

void push(int node, int l, int r) {
    if (lz[node]) {
        int mid = l + (r-l)/2;
        apply(2*node, l, mid);
        apply(2*node+1, mid+1, r);
        lz[node] = false;
    }
}

void toggle(int node, int l, int r, int lx, int rx) {
    if (l > rx || r < lx) return;
    if (l >= lx && r <= rx) {
        apply(node, l, r);
        return;
    }
    push(node, l, r);
    int mid = l+(r-l)/2;
    toggle(2*node, l, mid, lx, rx);
    toggle(2*node+1, mid+1, r, lx, rx);
    t[0][node] = t[0][2*node] ^ t[0][2*node+1];
    t[1][node] = t[1][2*node] ^ t[1][2*node+1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tt = 1; tt <= T; tt++) {
        int n; cin >> n;
        t.assign(2, vector<int>(4*n, 0));
        lz.assign(4*n, false);
        a.assign(n, 0);
        b.assign(n, false);
        for (int& x : a) cin >> x;
        string s; cin >> s;
        for (int i = 0; i < n; i++) b[i] = s[i]=='1';
        build(1, 0, n-1);
        int q; cin >> q;
        vector<tuple<int,int,int>> stuff;
        for (int i = 0; i < q; i++) {
            int type; cin >> type;
            if (type == 1) {
                int l, r; cin >> l >> r; l--; r--;
                stuff.push_back({1, l, r});
            } else {
                int g; cin >> g;
                stuff.push_back({2,g,4});
            }
        }
        vector<int> outputs;
        for (int i = 0; i < q; i++) {
            //begin
            auto [type, first, second] = stuff[i];
            if (type == 1) {
                toggle(1, 0, n-1, first, second);
            } else {
                outputs.push_back(t[first][1]);
            }
            //end
        }
        for (int x : outputs) cout << x << " ";
        cout << "\n";
    }
}
