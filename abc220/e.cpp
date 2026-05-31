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
typedef modint998244353 mint;

int main(){
    ll N,D; cin>>N>>D;
    vector<mint> p2(N+1,1);
    rep(i,N) p2[i+1] = p2[i]*2;
    vector<mint> smp(N+5);
    rep(i,N+4) smp[i+1] = smp[i]+p2[i];
    mint ans=0;
    rep(i,N){
        ll pmx = i;
        if(pmx+N-1 < D)continue;
        if(pmx > D) pmx = D;
        ll pmn = 0;
        if(i+D >= N) {
            ll r = (i+D-(N-1));
            pmn = (r+1)/2;
        }
        ll p = 0;
        if(D>=2){
            ll t = D/2;
            if(t<=pmn) p+=pmn-t+1;
        }
        ll r = D-pmn;
        ll l = D-pmx;
        ans+=p2[i]*(smp[r+1]-smp[l]-p);
    }
    cout<<ans.val()<<endl;
    return 0;
}