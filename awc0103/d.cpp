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
    ll N,S;
    cin >> N >> S;
    vector<ll> W,V,C;;
    rep(i,N) {
        ll w,v,c; cin>>w>>v>>c;
        ll p = 1;
        ll c2=c;
        while(c){
            W.push_back(p*w);
            V.push_back(p*v);
            c -= p;
            if(2*p <= c) p*=2;
            else p=c;
        }
    }
    ll M = W.size();
    vector<ll> dp(S+1,-INF);
    dp[0] = 0;
    rep(i,M){
        vector<ll> dp2=dp;
        rep(s,S){
            ll nx = s+W[i];
            if(nx>S) break;
            chmax(dp2[nx], dp[s]+V[i]);
        }
        swap(dp,dp2);
    }
    cout<<max(-1ll, dp[S])<<endl;
    return 0;
}