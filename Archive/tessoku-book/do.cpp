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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N; cin>>N;
    vector<ll> score(4);
    rep(i,N) {
        ll a,b; cin>>a>>b;
        if(a+b > 0) score[0] += a + b;
        if(a-b > 0) score[1] += a - b;
        if(-a+b > 0) score[2] += -a + b;
        if(-a-b > 0) score[3] += -a - b;
    }
    ll ans = 0;
    rep(i,4) chmax(ans, abs(score[i]));
    cout << ans << endl;
    return 0;
}