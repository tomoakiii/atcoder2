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
    int R=0,W=0,Q=0;
    rep(i,N) {
        char c; cin>>c;
        if(c=='R') R++;
        if(c=='W') W++;
        if(c=='?') Q++;
    }
    ll ans = abs(R-W);
    if(ans >= Q) cout<<ans-Q<<endl;
    else {
        Q-=ans;
        cout << Q%2 << endl;
    }
    return 0;
}