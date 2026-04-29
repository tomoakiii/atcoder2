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
    ll N,M;
    cin >> N >> M;
    vector L1(M, unordered_set<ll>{});
    vector<bool> R(M);
    rep(i,M) {
        ll K; cin>>K;
        rep(j,K) {
            int s; cin>>s; s--;
            L1[i].insert(s);
        }
        int r; cin>>r;
        R[i]=(r==1);
    }
    ll full=1ll<<N;
    ll ans=INF;
    rep(S,full){
        bool flg=true;
        rep(k,M){
            ll cnt=0;
            for(auto s:L1[k]) {
                if(S>>s & 1)cnt++;
            }
            if(R[k] && cnt==0) flg=false;
            if(!R[k] && cnt>0) flg=false;
        }
        if(!flg) continue;
        ll sm=0;
        rep(i,N) {
            if(S>>i & 1) sm++;
        }
        chmin(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}