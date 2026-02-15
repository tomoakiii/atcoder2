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

int main(){
    ll N,L;
    cin>>N>>L;
    ll ans = 0;
    rep(i,N) {
        ll A; char B; cin>>A>>B;
        if(B=='E') {
            chmax(ans, L-A);
        } else {
            chmax(ans, A);
        }
    }
    cout << ans << endl;
    return 0;
}