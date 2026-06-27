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
    vector<pair<int,int>> uv(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[i]={u,v};
    }
    vector<int> P(N);
    rep(i,N)P[i]=i+1;
    ll ans=0;
    do{
        bool flg=true;
        rep(i,M){
            if(P[uv[i].first] > P[uv[i].second]) flg=false;
        }
        if(!flg)continue;
        ll sm=0;
        rep(i,N)sm+=A[i]*P[i];
        chmax(ans,sm);
    }while(next_permutation(P.begin(), P.end()));

    cout<<ans<<endl;
    return 0;
}