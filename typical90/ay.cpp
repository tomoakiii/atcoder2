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
    ll N, K, P;
    cin >> N >> K >> P;
    ll Nh = N/2;
    ll Nh2 = N - Nh;
    vector<ll> A(Nh), B(Nh2);
    rep(i,Nh) cin >> A[i];
    rep(i,Nh2) cin >> B[i];
    vector p1(K+1, vector<ll>{}), p2(K+1, vector<ll>{});    
    rep(p, 2) {        
        rep(i, 1ll<<Nh) {
            ll sm = 0;
            ll cnt = 0;
            rep(k, Nh) {
                if(i>>k & 1) {
                    sm += A[k];
                    cnt++;
                    if(cnt > K) break;
                }
            }
            if(cnt <= K) p1[cnt].emplace_back(sm);
        }
        rep(k, K+1) {
            sort(p1[k].begin(), p1[k].end());
        }
        swap(B, A);
        swap(p1, p2);
        swap(Nh, Nh2);
    }
    ll ans = 0;
    rep(k, K+1) {
        ll k2 = K-k;
        for(auto s: p1[k]) {
            ll id = lower_bound(p2[k2].begin(), p2[k2].end(), P-s+1) - p2[k2].begin();
            if(id > 0) ans += id;
        }
    }
    cout << ans << endl;
    return 0;
}

