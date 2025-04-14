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
    vector<string> S(N), T(M);
    rep(i,N) cin>>S[i];
    rep(i,M) cin>>T[i];
    rep(i,N-M+1) rep(j,N-M+1) {
        bool flg = true;
        rep(i2, M) rep(j2, M) {
            if(T[i2][j2] != S[i+i2][j+j2]) flg = false;
        }
        if (flg) {
            cout << i+1 << " " << j+1 << endl;
        }
    }
    return 0;
}