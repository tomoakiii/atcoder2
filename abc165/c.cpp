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
struct ST{
    int a,b,c,d;
    const bool operator<(const ST &x) const{
        return a < x.a;
    };
};
int main(){
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<ST> A(Q);

    rep(i,Q) {
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        a--, b--;
        A[i] = {a,b,c,d};
    }
    sort(A.begin(), A.end());
    vector<ll> dp(11,-1);
    dp[0] = 0;
    rep(i,Q) {
        int a = A[i].a;
        int b = A[i].b;
        dp[i]
    }
    return 0;
}
