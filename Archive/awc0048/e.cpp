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
typedef modint1000000007 mint;
int main(){
    ll N,K,M;
    cin >> N >> K >> M;
    ll N1=N/2;
    ll N2=N-N1;
    vector<ll> A(N1), B(N2);
    rep(i,N1) cin>>A[i];
    rep(i,N2) cin>>B[i];
    vector<unordered_map<ll,ll>> mp1(N1+1),mp2(N2+1);
    rep(kkk,2){
        ll full = 1ll<<N1;
        rep(S,full) {
            int cnt=0;
            ll sm=0;
            rep(i,N1) {
                if(S>>i & 1) {
                    cnt++;
                    sm+=A[i];
                }
            }
            sm%=M;
            mp1[cnt][sm]++;
        }
        swap(mp1,mp2); swap(A,B); swap(N1,N2);
    }
    mint ans=0;
    rep(i,N1+1){
        ll ti = K-i;
        if(ti<0) break;
        if(ti>N2) continue;
        for(auto [v,c]:mp1[i]) {
            ll tgt=(M-v)%M;
            if(mp2[ti].contains(tgt)) {
                ans+=(c*mp2[ti][tgt]);
                // cerr<<i<<" "<<ti<<" "<<v<<" "<<tgt<<" "<<c<<" "<<mp2[ti][tgt]<<endl;
            }
        }
    }
    cout<<ans.val()<<endl;
    return 0;
}