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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<ll> P(N),Q(N);
    rep(i,N)cin>>P[i];
    rep(i,N)cin>>Q[i];
    rep(i,M){
        int K; cin>>K;
        ll ans = 0;
        rep(j,K){
            ll s; cin>>s; s--;
            ans += P[s]-Q[s];
        }
        cout<<ans<<endl;
    }

    return 0;
}