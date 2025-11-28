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
    ll A,B,Q; cin>>A>>B>>Q;
    vector<ll> S(A);
    vector<ll> T(B);
    rep(i,A) cin>>S[i];
    rep(i,B) cin>>T[i];
    sort(S.begin(),S.end());
    sort(T.begin(),T.end());

    rep(i,Q) {
        ll x; cin>>x;
        ll ans = INF;
        vector<ll> s; vector<ll> t;
        {
            auto it = lower_bound(S.begin(), S.end(), x);
            if(it != S.end()) s.push_back(*it);
            if(it != S.begin()) {
                it--;
                s.push_back(*it);
            }
        }
        auto it = lower_bound(T.begin(), T.end(), x);
        if(it != T.end()) t.push_back(*it);
        if(it != T.begin()) {
            it--;
            t.push_back(*it);
        }
        for(auto ss: s){
            for(auto tt: t) {
                ll sm = 0;
                if(abs(ss-x) < abs(tt-x)) {
                    sm += abs(ss-x);
                    sm += abs(tt-ss);
                } else {
                    sm += abs(tt-x);
                    sm += abs(tt-ss);
                }
                chmin(ans,sm);
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}