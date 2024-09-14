#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N, 0);
    vector<ll> B(M, 0);
    rep(i, N) {cin >> A[i];}
    rep(i, M) {cin >> B[i];}
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int idB = 0, idA = 0;
    ll sm = 0;
    while(true) {
        if (B[idB] <= A[idA]) {
            sm += A[idA];
            if (idB == M-1) {
                cout << sm << endl;
                return 0;
            }
            idB++;                                    
        }
        idA++;
        if (idA == N) {
            cout << -1 << endl;
            return 0;
        }
    }
    return 0;
}