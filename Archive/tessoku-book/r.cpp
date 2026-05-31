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
    ll N,M; cin>>N>>M;
    ll N2 = N/3;
    ll Nr = N-N2-N2;
    ll sz[] = {N2,N2,Nr};
    vector SM(3, vector<bool>(M+1));
    rep(kk,3) {
        ll n = sz[kk];
        vector<ll> A(n);
        rep(i,n) cin>>A[i];
        rep(k, 1ll<<n) {
            ll sm = 0;
            rep(i,n) {
                if(k>>i&1) sm += A[i];
            }
            if(sm<=M) SM[kk][sm]=true;
        }
    }

    rep(i,M+1) {
        if(!SM[0][i]) continue;
        rep(j,M+1) {
            if(!SM[1][j]) continue;
            if(i+j>M) continue;
            if(SM[2][M-i-j]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}