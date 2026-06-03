#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;

void inizia(int N, vector<int> A) {
    n = N;
    a = vector<int>(n*2);
    for (int i = 0; i < n; i++) {
        a[i+n] = A[i];
    }
    for (int i = n-1; i > 0; i--) {
        a[i] = max(a[i*2], a[i*2+1]);
    }
}

void aggiorna(int p, int x) {
    p += n;
    a[p] = x;
    for (int i = p; i > 1; i /= 2) {
        a[i/2] = max(a[i], a[i^1]);
    }
}

int massimo(int l, int r) {
    int ans = -1;

    l += n;
    r += n;
    r += 1;

    while (l < r) {
        if (l%2) ans = max(ans, a[l++]);
        if (r%2) ans = max(ans, a[--r]);

        l /= 2;
        r /= 2;
    }

    return ans;
}
