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
    ll H,W,N;
    cin >> H >> W >> N;
    vector A(H,vector<ll>(W));
    rep(i,H) rep(j,W) cin>>A[i][j];
    set<ll> B;
    rep(i,N){
        ll b; cin>>b;
        B.insert(b);
    }
    ll mx = 0;
    rep(i,H) {
        ll t = 0;
        rep(j,W) {
            if(B.contains(A[i][j])) t++;
        }
        chmax(mx, t);
    }
    cout<<mx<<endl;
    return 0;
}