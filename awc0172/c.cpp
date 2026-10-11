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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<bool> B(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        if(A[u]>A[v])B[v]=true;
        else if(A[u]<A[v])B[u]=true;
    }
    ll ans=0;
    for(auto b:B)if(b)ans++;
    cout<<ans<<endl;
    return 0;
}