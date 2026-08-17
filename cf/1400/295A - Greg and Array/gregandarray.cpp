#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> a, t, z;

void build(int no, int nl, int nr) {
    if (nl == nr) {
        t[no] = a[nl];
        return;
    }
    int mid = (nr+nl)/2;
    build(no*2, nl, mid);
    build(no*2+1, mid+1, nr);
    t[no] = t[no*2] + t[no*2+1];
}

void apply(int no, int nl, int nr, int v) {
    // cout << "t[" << no << "] " << t[no] << " -> ";
    t[no] += (nr-nl+1)*v;
    // cout << t[no] << "\n";
    z[no] += v;
}

void push(int no, int nl, int nr) {
    if (z[no] == 0) return;
    int mid = (nr+nl)/2;
    apply(no*2, nl, mid, z[no]);
    apply(no*2+1, mid+1, nr, z[no]);
    z[no] = 0;
}

void upd(int no, int nl, int nr, int l, int r, int v) {
    if (nl > r || nr < l) return;
    if (nl >= l && nr <= r) {
        apply(no, nl, nr, v);
        return;
    }
    push(no, nl, nr);
    int mid = (nr+nl)/2;
    upd(no*2, nl, mid, l, r, v);
    upd(no*2+1, mid+1, nr, l, r, v);
    t[no] = t[no*2] + t[no*2+1];
}

void qry(int no, int nl, int nr, int l, int r) {
    if (nl > r || nr < l) return;
    if (nl >= l && nr <= r) return;
    push(no, nl, nr);
    int mid = (nr+nl)/2;
    qry(no*2, nl, mid, l, r);
    qry(no*2+1, mid+1, nr, l, r);
}

void printall(int no, int nl, int nr) {
    if (nl == nr) {
        // cout << "t[" << no << "]" << nl << "=" << t[no] << " ";
        cout << t[no] << " ";
        return;
    }
    push(no, nl, nr);
    int mid = (nr+nl)/2;
    printall(no*2, nl, mid);
    printall(no*2+1, mid+1, nr);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    a.assign(n, 0);
    t.assign(n*4, 0);
    z.assign(n*4, 0);
    vector<int> dfp(m, 0);
    vector<int> dfm(m, 0);

    // queue to store ops and then mult the strength of the q elements by df
    queue<tuple<int,int,int>> updq;

    for (auto& in : a) cin >> in;
    // for (auto& in : a) cout << in << " ";
    // cout << "\n\n";
    build(1, 0, n-1);
    for (int i = 0; i < m; i++) {
        int lx, rx, dx; cin >> lx >> rx >> dx; lx--; rx--;
        updq.push({lx, rx, dx});
    }

    for (int i = 0; i < k; i++) {
        int x, y; cin >> x >> y; x--; y--;
        // qry(1, 0, n-1, x, y);
        dfp[x]++; dfm[y]--;
        // need to put hte contents of this into an array, ++ing the range starts and --ing the range ends, then i need to qry the whole array once, and have them reference how much to multiply their own t += v operation by via another array
    }

    int hold = -0;
    vector<int> mult(m);
    for (int i = 0; i < m; i++) {
        hold += dfp[i];
        mult[i] = hold;
        // cout << "mult[" << i << "]: " << hold << "\n";
        hold += dfm[i];
    }

    int i = 0;
    while (!updq.empty()) {
        // cout << "\n" << i << "\n";
        auto [l, r, v] = updq.front(); updq.pop();
        upd(1, 0, n-1, l, r, v*mult[i]);
        i++;
    }



    printall(1, 0, n-1);
}
