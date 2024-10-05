#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<vector<char>> G;
    G.resize(1);
    G[0].resize(1, '#');    

    auto func = [&](vector<vector<char>> A) -> vector<vector<char>> {
        vector<vector<char>> C;
        C.resize(A.size() * 3);
        for (int j=0; j<C.size(); j++){
            C[j].resize(A.size() * 3, '.');
        }
        for (int i = 0; i < A.size() * 3; i += A.size()) {
            for (int j = 0; j < A.size() * 3; j += A.size()) {
                if (i == A.size() && j == A.size()) continue;
                for (int y = 0; y < A.size(); y++) for (int x = 0; x < A.size(); x++){
                    C[i+y][j+x] = A[y][x];
                }
            }
        }
        return C;
    };
    for (int i=1; i<=N; i++) {
        auto G2 = func(G);
        G = G2;
    }
    for (int y = 0; y < G.size(); y++) {
        for (int x = 0; x < G.size(); x++){
            cout << G[y][x];
        }
        cout << endl;
    }
    return 0;
}