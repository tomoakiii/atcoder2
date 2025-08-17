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
    ll N;
    cin >> N;
    vector<ll> R(N), C(N);
    ll rm=0, cm=0, rmn=INF, cmn = INF;
    rep(i,N) {
        cin>>R[i]>>C[i];
        chmax(rm, R[i]); chmax(cm, C[i]);
        chmin(rmn, R[i]); chmin(cmn, C[i]);
    }
    ll tr = (rm+rmn)/2;
    ll tc = (cm+cmn)/2;
    ll ans = 0;
    chmax(ans, max(abs(rm-tr), abs(rmn-tr)));
    chmax(ans, max(abs(cm-tc), abs(cmn-tc)));
    cout << ans << endl;

    return 0;
}