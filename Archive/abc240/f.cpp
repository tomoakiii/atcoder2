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

void solve(){
    ll N,M; cin>>N>>M;
    vector<ll> A(N),L(N);
    rep(i,N) cin>>A[i]>>L[i];
    ll cv=0, cx=0, ans=A[0];
    auto cal_x = [&](ll t, ll v, ll a)->ll{
        return t*v + t*(t+1)*a/2;
    };
    rep(i,N){
        ll x = cal_x(1, cv, A[i]);
        chmax(ans, cx+x);
        if(A[i]<0 && cv>0){
            // v0 + at = v = 0
            // t = v0 / a
            ll t=-cv/A[i];
            rep(dt,2) {
                ll x = cal_x(t, cv, A[i]);
                if(1<=t && t<=L[i])chmax(ans, cx+x);
                t++;
            }
        }
        cx += cal_x(L[i], cv, A[i]);
        cv += L[i]*A[i];
        chmax(ans, cx);
    }
    cout<<ans<<endl;
}


int main(){
    int T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}