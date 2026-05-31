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
    map<multiset<ll>, ll> mp;
    ll N; cin>>N;
    ll B[3];
    rep(i,3) cin>>B[i];
    vector<ll> L(N);
    rep(i,N) cin>>L[i];
    ll K = 1;
    rep(i,N) K *= 4;
    ll ans = INF;
    rep(k,K) {
        vector<ll> P(4);
        vector<int> cnt(3);
        ll q = k;
        rep(i,N) {
            if(q%4 < 3){
                P[q%4] += L[i];
                cnt[q%4]++;
            }
            q /= 4;
        }
        sort(P.rbegin(),P.rend());
        if(P[0]==0 || P[1]==0 || P[2]==0) continue;
        ll sm = 0;
        rep(i,3) {
            sm += abs(P[i]-B[i]);
            sm += 10*(cnt[i]-1);
        }
        chmin(ans,sm);
    }
    cout<<ans<<endl;
    return 0;
}