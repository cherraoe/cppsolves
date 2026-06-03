#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000;
int n, seg[2 * MAXN];

void build() {
    for (int i = n-1; i > 0; i--) {
        seg[i] = max(seg[2*i], seg[2*i+1]);
    }
}

void update(int p, int val) {
    for (seg[p += n] = val; p > 1; p >>= 1) {
        seg[p >> 1] = max(seg[p], seg[p ^ 1]);
    }
}

int query(int l, int r) {
    int ans = -1;

    l += n;
    r += n;

    while (l < r) {
        if (l%2 == 1) {
            ans = max(ans, seg[l++]);
        }
        if (r%2 == 1) {
            ans = max(ans, seg[--r]);
        }

        l /= 2;
        r /= 2;
    }
}
