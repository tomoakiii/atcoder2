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
    ll N;
    cin >> N;
    vector<ll> P(N),Q(N);
    rep(i,N) cin>>P[i]>>Q[i];
    ll ful = 1ll<<N;
    int ans = INFi;
    rep(S,ful) {
        mint sp=1, qp=1;
        int cnt=0;
        rep(i,N) {
            if(S>>i & 1) {
                sp *= P[i];
                qp *= Q[i];
                cnt++;
            }
        }
        if(cnt < 2) continue;
        if(sp.val() == qp.val()) {
            chmin(ans, cnt);
        }
    }
    if(ans==INFi) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}