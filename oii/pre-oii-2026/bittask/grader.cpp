#include <vector>
#include <iostream>

using namespace std;

vector<int> assegna(int N, int M, vector<vector<int>> S);

int main() {
    
    int N, M;
    cin>>N>>M;
    
    vector<vector<int>> S(N);

    for(int i=0; i<N; i++) {
        int K;
        cin>>K;

        S[i].resize(K);

        for(int j=0; j<K; j++) {
            cin>>S[i][j];
        }
    }
    
    vector<int> P = assegna(N, M, S);

    cout<< size(P) << "\n";
    
    for(int i:P)
        cout<<i<<" ";
    cout<<"\n";
}
