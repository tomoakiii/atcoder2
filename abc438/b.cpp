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
    string S,T; cin>>S>>T;
    ll ans = INF;
    for(int i=0; i<N-M+1; i++) {
        ll cnt = 0;
        rep(j,M) {
            ll si = S[i+j], tj = T[j];
            ll t;
            if(si >= tj) t = abs(si - tj);
            else t = si + 10 - tj;
            cnt += t;
        }
        chmin(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}