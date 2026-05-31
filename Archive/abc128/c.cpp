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
    vector S(M, vector<int>{});
    rep(i,M) {
        int k; cin>>k;
        rep(j,k) {
            int s; cin>>s;
            s--;
            S[i].push_back(s);
        }
    }
    vector<int> P(M);
    rep(i,M) cin>>P[i];
    ll ans = 0;
    rep(k, 1<<N) {
        bool flg = true;
        rep(i,M) {
            int sm = 0;
            for(auto s: S[i]) if(k>>s & 1) sm++;
            if(sm%2 != P[i]) {
                flg = false;
                break;
            }
        }
        if(flg) ans++;
    }
    cout << ans << endl;
    return 0;
}