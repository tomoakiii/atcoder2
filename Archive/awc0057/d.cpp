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
    ll N,K,M;
    cin >> N >> K >> M;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<tuple<int,int,ll>> LRP(M);
    rep(i,M) {
        int l,r; ll p;
        cin>>l>>r>>p;
        l--, r--;
        LRP[i] = make_tuple(l,r,p);
    }
    ll ful=1ll<<N;
    ll ans=0;
    rep(S,ful) {
        ll sm=0;
        ll cnt=0;
        rep(i,N) {
            if(S>>i & 1) {
                sm += A[i];
                cnt++;
            }
        }
        if(cnt>K) continue;
        for(auto [l,r,p] : LRP) {
            bool flg=false;
            for(int j=l; j<=r; j++) {
                if(S>>j & 1) {
                    flg=true;
                }
            }
            if(flg) sm+=p;
        }
        chmax(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}