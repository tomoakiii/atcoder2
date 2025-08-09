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
    int h,w; cin>>h>>w;
    vector<string> S(h);
    rep(i,h) cin>>S[i];
    ll ans = 0;
    rep(i,h-1) {
        rep(j,w-1) {
            int b = 0;
            rep(x,2) rep(y,2) if(S[i+y][j+x]=='#')b++;
            if(b==1 || b==3) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}