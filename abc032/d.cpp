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
    ll N, M;
    cin >> N >> M;
    vector<ll> V(N), W(N);
    ll mxw = 0;
    rep(i,N) {
        cin>>V[i]>>W[i];
    }
    if(N <= 30) {
        ll N1 = N/2;
        ll N2 = N - N1;
        ll ans = 0;
        map<ll,ll> mp1, mp2;
        rep(kkk,2){
            rep(k, 1ll<<N1) {
                ll smv = 0, smw = 0;
                rep(i, N) {
                    if(k>>i & 1) {
                        smv += V[i];
                        smw += W[i];
                    }
                }
                if(!mp1.contains(smw)) mp1[smw] = smv;
                else chmax(mp1[smw], smv);
            }
            swap(N1,N2);
            swap(mp1,mp2);
            reverse(V.begin(),V.end());
            reverse(W.begin(),W.end());
        }
        ll mx = 0;
        for(auto [w,v]:mp2) {
            chmax(mx, v);
            mp2[w] = mx;
        }
        for(auto [w,v]: mp1) {
            auto it = mp2.lower_bound(M-w);
            if(it->first > M-w) it--;
            if(it == mp2.end()) continue;
            chmax(ans, v + it->second);
        }
        cout << ans << endl;
        return 0;
    }
    if(M*N <= 2e6) {
        vector<ll> dp(M+1,0);
        dp[0] = 0;
        rep(i,N) {
            auto dp_new = dp;
            rep(k, M+1){
                if(k + W[i] <= M) {
                    chmax(dp_new[k+W[i]], dp[k] + V[i]);
                }
            }
            swap(dp,dp_new);
        }
        ll ans = 0;
        rep(w,M+1) chmax(ans, dp[w]);
        cout<<ans<<endl;
        return 0;
    }
    {
        const ll dpsz = 1000*N+10;
        vector<ll> dp(dpsz,INF);
        dp[0] = 0;
        rep(i,N) {
            for(ll k=dpsz-1-V[i]; k>=0; k--){
                chmin(dp[k+V[i]], dp[k] + W[i]);
            }
        }
        for(ll k=dpsz-1; k>=0; k--) {
            if(dp[k] <= M) {
                cout << k << endl;
                return 0;
            }
        }
        return 0;


    }
    return 0;
}