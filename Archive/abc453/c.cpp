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
    vector<ll> A(N);
    rep(i,N){
        cin>>A[i];
    }
    ll ful=1ll<<N;
    ll ans=0;
    rep(S,ful) {
        ll cur=1;
        ll sm=0;
        rep(i,N) {
            ll nc;
            auto a=A[i];
            if(S>>i & 1) {
                nc=cur+a;
            } else {
                nc=cur-a;
            }
            if((nc>=1 && cur<=0)||(nc<=0 && cur>=1)) sm++;
            cur=nc;
        }
        chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}