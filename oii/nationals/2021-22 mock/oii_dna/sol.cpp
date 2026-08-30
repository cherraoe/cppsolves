#include <bits/stdc++.h>
using namespace std;

// bool test(string T);
// string analizza(int N) {
//     string c;
//     queue<tuple<string,int>> q;
//     q.push({"0", 0});
//     while (!q.empty()) {
//         auto [a, type] = q.front(); q.pop();
//         if (a.size() > N) break;
//         if (test(a)) {
//             a.push_back('0');
//             q.push({a, 0});
//         } else if (type == 0) {
//             a.pop_back();
//             a.push_back('1');
//             q.push({a, 1});
//         } else if (type == 1) {
//             a.pop_back();
//             a = '0'+a;
//             q.push({a, 2});
//         } else if (type == 2) {
//             a.erase(a.begin());
//             a = '1'+a;
//             q.push({a, 3});
//         } else if (type == 3) {
//             c = a;
//             cout << c;
//         }
//     }
//     return c;
// }
