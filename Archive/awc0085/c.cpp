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
    ll ans = 0;
    vector<ll> T(N),P(N);
    rep(i,N) {
        cin>>T[i]>>P[i];
    }
    ll ful=1ll<<N;
    rep(S,ful){
        ll cost=0;
        ll score = 0;
        rep(i,N){
            if((S>>i) % 2) cost+=T[i], score+=P[i];
        }
        if(cost <= M){
            chmax(ans, score);
        }
    }
    cout<<ans<<endl;
    return 0;
}