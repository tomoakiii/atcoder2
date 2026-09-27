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
    ll N,M,K,B;
    cin >> N>>M>>K>>B;
    vector dp(M+1, vector<ll>(K+1,-INF));
    dp[0][0]=0;
    struct st{
        ll d,v,t;
    };
    vector<st> DVT(N);
    rep(i,N)cin>>DVT[i].d>>DVT[i].v>>DVT[i].t;
    auto comp=[](const st &a, const st &b)->bool{
        return a.t < b.t;
    };
    sort(DVT.begin(),DVT.end(),comp);
    rep(i,N){
        auto dp2=dp;
        ll d=DVT[i].d,v=DVT[i].v,t=DVT[i].t; 
        rep(j,M){
            int nj=j+d;
            if(nj>t)break;
            rep(k,K+1){
                if(dp[j][k]<0)continue;
                ll b=0;
                int nk;
                if(k==K-1){
                    b=B, nk=K;
                } else if (k==K){
                    nk=K;
                } else {
                    nk = k+1;
                }
                chmax(dp2[nj][nk], dp[j][k]+v+b);
            }
        }
        swap(dp,dp2);
    }
    ll ans = 0;
    rep(i,M+1)rep(k,K+1)chmax(ans,dp[i][k]);
    cout<<ans<<endl;
    return 0;
}