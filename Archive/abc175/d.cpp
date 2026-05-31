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
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N), C(N);
    rep(i,N) {
        cin>>P[i];
        P[i]--;
    }
    rep(i,N) cin>>C[i];
    ll ans = -INF;

    rep(i,N) {
        vector<ll> tsc(N, -INF);
        vector<ll> stp(N, -INF);
        auto func = [&](auto func, int cur, ll d, ll score) -> void{
            score += C[cur];            
            chmax(ans, score);
            if(d == K) {
                return;
            }
            if(tsc[cur] != -INF) {
                ll cyc = score - tsc[cur];
                ll s = d - stp[cur];                
                ll K2 = K - d;
                ll p = K2/s;
                if(cyc > 0) score += p*cyc;
                K2 -= p*s;
                chmax(ans, score);
                while(K2--) {
                    int nx = P[cur];
                    score += C[nx];
                    chmax(ans, score);
                    cur = nx;
                }                
                return;
            }
            tsc[cur] = score;
            stp[cur] = d;
            int nx = P[cur];
            func(func, nx, d+1, score);
        };
        func(func, i, 1, 0);
    }
    cout << ans << endl;
    return 0;
}