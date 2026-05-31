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
    ll N,K;
    cin >> N >> K;
    vector T(N, vector<ll>(N));
    rep(i,N) rep(j,N) cin>>T[i][j];
    vector<ll> ord(N-1);
    rep(i,N-1) ord[i] = i+1;
    ll ans = 0;
    do{
        ll sm = T[0][ord[0]];
        rep(i,N-2) sm += T[ord[i]][ord[i+1]];
        sm += T[ord[N-2]][0];
        if(sm == K) ans++;
    }while(next_permutation(ord.begin(), ord.end()));
    cout << ans << endl;
    return 0;
}