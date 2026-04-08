#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;
typedef modint998244353 mint;

int main(){
    ll N,D; cin>>N>>D;
    vector<ll>P(N),W(D);
    mint S=0;
    rep(i,N){
      cin>>P[i];
      S+=P[i];
    }
    mint inv = 1;
    rep(i,N) inv*= S;
    mint WS=0;
    rep(i,D){
      cin>>W[i];
      WS+=W[i];
    }
    mint f = 1;
    rep(i,N){
      mint t;
      t = WS*P[i];
      f *= t;
    }
    f /= inv;
    cout<<f.val()<<endl;
    return 0;
}