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
    ll N,B;
    cin >> N >> B;
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    vector<ll> C(N);
    rep(i,N-1) cin>>C[i+1];
    rep(i,N-1) C[i+1]+=C[i];
    ll ans = 0;
    ll psm = 0;
    int r=0;
    rep(i,N) {
        while(r<N && C[r]-C[i] <= B) {
            psm+=P[r];
            r++;
        }
        chmax(ans,psm);
        psm -= P[i];
    }
    cout << ans << endl;
    return 0;
}