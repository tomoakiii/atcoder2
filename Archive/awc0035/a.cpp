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

int main(){
    ll N,M;
    cin >> N>>M;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    rep(i,M) {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        u--, v--;
        P[u]-=w;
        P[v]+=w;
    }
    int ans;
    ll mx=0;
    rep(i,N) {
        if(chmax(mx,P[i]))ans=i;
    }
    cout<<ans+1<<endl;
    return 0;
}