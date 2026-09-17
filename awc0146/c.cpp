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
    ll N,M,K;
    cin >> N >> M >> K;
    vector<ll> A(N),B(N+1);
    rep(i,N) cin>>A[i];
    rep(i,M){
        ll x,y,z; cin>>x>>y>>z; x--,y--;
        B[x]+=z; B[y+1]-=z;
    }
    rep(i,N)B[i+1]+=B[i];
    rep(i,N)B[i]+=A[i];
    ll ans = 0;
    rep(i,N) if(B[i]>=K) ans++;
    cout<<ans<<endl;
    return 0;
}