#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    rep(i,N-M+1) {
        rep(j, N-M+1) {
            bool flg = true;
            rep(y, M) {
                rep(x, M){
                    if(A[i+y][j+x] != B[x][y]) {
                        flg = false;
                        break;
                    }
                }
            }
            if(flg) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}