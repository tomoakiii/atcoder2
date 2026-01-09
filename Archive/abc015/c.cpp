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
    ll N,K;
    cin >> N >> K;
    ll p = 1;
    vector T(N, vector<ll>(K));
    rep(i,N) rep(j,K) cin>>T[i][j];
    rep(i,N) p*=K;
    rep(kkk, p) {
        ll kk = kkk;
        ll X = 0;
        rep(i,N) {
            int k = kk % K;
            X = X ^ T[i][k];
            kk /= K;
        }
        if(X==0) {
            cout<<"Found"<<endl;
            return 0;
        }
    }
    cout << "Nothing" << endl;
    return 0;
}