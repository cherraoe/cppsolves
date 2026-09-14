#include <vector>
#include <iostream>

using namespace std;

long long acquista(int N, int M, int L, vector<int> X, vector<int> T);

int main() {
    int N, M, L;

    cin>>N>>M>>L;
    
    vector<int> X(N), T(M);

    for(auto &x:X) cin>>x;
    for(auto &t:T) cin>>t;

    long long C = acquista(N, M, L, X, T);

    cout<<C<<"\n";
}
