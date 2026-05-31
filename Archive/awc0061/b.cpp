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
    ll N;
    cin >> N;
    vector<ll> S(N),C(N-1);
    rep(i,N) cin>>S[i];
    rep(i,N-1) cin>>C[i];
    ll ans=S[0];
    ll a=S[0],b=0;
    rep(i,N-1){
        a+=S[i+1];
        b+=C[i];
        chmax(ans,a-b);
    }
    cout<<ans<<endl;
    return 0;
}