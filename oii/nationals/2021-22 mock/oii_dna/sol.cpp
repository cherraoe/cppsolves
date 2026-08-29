#include <bits/stdc++.h>
using namespace std;

string analizza(int N) {
    vector<string> c;
    queue<string> q;
    q.push("1");
    q.push("0");
    while (!q.empty()) {
        string root = q.front(); q.pop();
        if (test(root)) {
            root.push_back('0');
            q.push(root);
            root.pop_back();
            root.push_back('1');
            q.push(root);
        } else {

        }
// need to dp based off of parents and get progressively more specific.
    }
}
