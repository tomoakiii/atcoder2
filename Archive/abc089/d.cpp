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
typedef pair<int,int> pii;

int main(){
    ll H,W,D;
    cin >> H>>W>>D;
    vector<pii> P(H*W);

    rep(i,H) rep(j,W) {
        ll a; cin>>a;
        a--;
        P[a] = {i,j};
    }

    vector<ll> PW(H*W);
    rep(i,D) {
        int st = i;
        auto [y,x] = P[st];
        while(st + D < H*W) {
            ll nst = st + D;
            auto [ny, nx] = P[nst];
            PW[nst] = PW[st] + abs(y-ny) + abs(x-nx);
            y = ny, x = nx, st = nst;
        }
    }

    int Q; cin>>Q;
    while(Q--) {
        int l,r; cin>>l>>r; l--,r--;
        cout<<PW[r] - PW[l]<<endl;
    }
    return 0;
}