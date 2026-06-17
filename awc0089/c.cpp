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
    vector<ll> C(N-1);
    rep(i,N-1) cin>>C[i];
    ll ans = 0;
    ll cost = 0;
    ll psm = 0;
    int r=-1;
    rep(i,N-1) {
        while(r+1 < N-1 && cost+C[r+1] <= B) {
            r++;
            cost+=C[r];
            psm+=P[r];
        }
        if(r<i) {
            r=i; continue;
        }
        cost -= C[i];
        psm -= P[i];
        chmax(ans,psm);
    }
    cout << ans << endl;
    return 0;
}