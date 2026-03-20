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
    ll mxw = 0, mxv = 0;
    rep(i,N) {
        cin>>V[i]>>W[i];
        chmax(mxw, W[i]);
        chmax(mxv, V[i]);
    }
    if(N <= 30) {
        ll N1 = N/2;
        ll ans = 0;
        map<ll,ll> mp1, mp2;
        ll off = 0;
        vector<ll> V2, W2;
        rep(i,N1) {
            V2.push_back(V.back());
            W2.push_back(W.back());
            V.pop_back();
            W.pop_back();
        }
        rep(kkk,2){
            N1 = V.size();
            rep(k, 1ll<<N1) {
                ll smv = 0, smw = 0;
                rep(i, N1) {
                    if((k>>i) & 1ll) {
                        smv += V[i];
                        smw += W[i];
                    }
                }
                if(smw > M) continue;
                chmax(ans, smv);
                if(!mp1.contains(smw)) mp1[smw] = smv;
                else chmax(mp1[smw], smv);
            }
            swap(mp1,mp2);
            swap(V,V2); swap(W,W2);
        }
        ll mx = 0;
        for(auto [w,v]:mp2) {
            chmax(mx, v);
            mp2[w] = mx;
        }
        mp2[INF] = 0;
        mp2[0] = 0;
        for(auto [w,v]: mp1) {
            auto it = mp2.upper_bound(M-w);
            it--;
            auto [smw, smv] = *it;
            if(w+smw <= M) chmax(ans, v+smv);
        }
        cout << ans << endl;
        return 0;
    } else if(mxw <= 1000) {
        vector<ll> dp(M+1,-INF);
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
    } else if(mxv <= 1000) {
        const ll dpsz = 1000*N+10;
        vector<ll> dp(dpsz,INF);
        dp[0] = 0;
        rep(i,N) {
            auto dp_new = dp;
            rep(k, dpsz){
                if(k+V[i]>=dpsz) break;
                chmin(dp_new[k+V[i]], dp[k] + W[i]);
            }
            swap(dp, dp_new);
        }
        for(ll k=dpsz-1; k>=0; k--) {
            if(dp[k] <= M) {
                cout << k << endl;
                return 0;
            }
        }
        return 0;
    } else {
        return -1;
    }
    return 0;
}