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
    ll N;
    cin >> N;
    vector<ll> A(N),P(N),B(N);
    vector uv(N, vector<int>{});
    rep(i,N) cin>>A[i];
    for(int i=1;i<N;i++) {
        cin>>P[i]; P[i]--;
        uv[P[i]].push_back(i);
    }
    rep(i,N) cin>>B[i];
    vector<ll> D(N);
    auto dfs=[&](auto self,int v)->void{
        if(v!=0) D[v] = D[P[v]] + A[v];
        for(auto u:uv[v]){
            self(self,u);
        }
    };
    D[0] = A[0];
    dfs(dfs,0);
    ll ans=0;
    for(int i=1;i<N;i++){
        ans+=B[i]*D[i];
    }
    cout<<ans<<endl;
    return 0;
}