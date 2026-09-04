#include <bits/stdc++.h>
using namespace std;

int rimembra(int n, int k, vector<int> v);

int main(){
    int N, K; cin >> N >> K;

    vector<int> V(N);
    for(int &x: V) cin >> x;

    cout << rimembra(N, K, V) << "\n";
}
