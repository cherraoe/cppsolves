#include <bits/stdc++.h>
using namespace std;

bool test (string qry);
string analizza (int N) {
    string s = "0";
    vector<string> h;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int t = q.front(); q.pop();
        // cout << "n="<<N<<" s="<<s.length()<<" "<< s << " t=" << t << endl;
        if (test(s)) {
            if (s.length() == N) return s;
            h.push_back(s);
            s.push_back('0');
            q.push(0);
        } else if (t == 0) {
            s.pop_back();
            s.push_back('1');
            q.push(1);
        } else if (t == 1) {
            s.pop_back();
            s = '0' + s;
            q.push(2);
        } else if (t == 2) {
            s.erase(s.begin());
            s = '1' + s;
            q.push(3);
        } else if (t == 3) {
            s.erase(s.begin());
            int l = 0, r = h.size()-1;
            s = "";
            while (l <= r) {
                int mid = l+(r-l)/2;
                if (test(h[mid])) {
                    s = h[mid];
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
            q.push(0);
        }
    }
    // cout << "returned " << s << endl;
    return s;
}
