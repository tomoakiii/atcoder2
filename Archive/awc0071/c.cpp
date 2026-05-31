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
    ll sm=0;
    rep(i,N) {
        cin>>A[i];
        sm+=A[i];
    }
    ll ans=1;
    for(ll k=2; k<=N; k++){
        if(sm%k!=0)continue;
        ll tgt=sm/k;
        ll sm=0;
        bool flg=true;
        rep(i,N){
            sm+=A[i];
            if(sm>tgt){
                flg=false;
                break;
            } else if(sm==tgt){
                sm=0;
                continue;
            }
        }
        if(flg)chmax(ans,k);
    }
    cout<<ans<<endl;
    return 0;
}