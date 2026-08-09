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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<ll> V(N),W(N),T(M);
    rep(i,N) cin>>V[i]>>W[i];
    rep(i,M) cin>>T[i];
    ll ful = 1ll<<N;
    ll ans = 0;
    rep(S,ful){
        ll p=S;
        ll sm=0;
        while(p){
            if(p%2)sm^=V[i];
            else sm^=W[i];
            p/=2; 
        }
        bool flg=0;
        rep(i,M) if(sm==T[i]) chmax(ans, sm);
    }
    return 0;
}