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
    ll N,L,Q;
    cin >> N >> L >> Q;
    vector<ll> A(N),R(N),V(N);
    rep(i,N) cin>>A[i]>>R[i]>>V[i];
    auto fnc = [&](ll t, ll s)->ll{
        ll ret = 0;
        ll div = 0;
        rep(i,N){
            ll a=A[i];
            ll x=R[i]+V[i]*t;
            x%=a;
            if(x>s)continue;
            //x+ka<=s
            // ka<=s-x
            ret+=1+(s-x)/a;
            if(x==0)div++;
        }
        return ret-div;
    };

    while(Q--){
        ll t,s,p; cin>>t>>s>>p;
        ll ans=1;
        ll fts=fnc(t,s);
        ll ng=-1, ok=s;
        while(ok-ng>1){
            ll c=(ok+ng)/2;
            if(fts-fnc(t,c) <= p) ok=c;
            else ng=c;
        }
        ans+=s-ng-1;
        ng=L, ok=s;
        while(ng-ok>1){
            ll c=(ok+ng)/2;
            if(fnc(t,c)-fts <= p) ok=c;
            else ng=c;
        }
        ans+=ng-s-1;
        cout<<ans<<endl;
    }
    return 0;
}