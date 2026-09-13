#include <iostream>
#include <variant>
#include <vector>
#include <utility>

using namespace std;

void init(int K, string S, vector<int> P);
variant<bool, pair<int, int>> imbroglia(int X, char C);

int main() {
    int K, Q;
    cin >> K >> Q;

    string S;
    vector<int> P(1 << K);

    cin >> S;
    for (int i = 0; i < (1 << K); i++)
        cin >> P[i];

    init(K, S, P);

    for (int i = 0; i < Q; i++) {
        int X;
        char C;
        cin >> X >> C;

        variant<bool, pair<int, int>> ans = imbroglia(X, C);
        if (holds_alternative<bool>(ans)) {
            if (get<bool>(ans)) {
                cout << "Ok\n";
            } else {
                cout << "Impossibile\n";
            }
        } else {
            auto [u, v] = get<pair<int, int>>(ans);
            cout << u << ' ' << v << '\n';
        }
    }
}
