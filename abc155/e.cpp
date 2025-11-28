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
    vector<ll> X(N),Y(N),Z(N);
    rep(i,N) cin>>X[i]>>Y[i]>>Z[i];
    ll K = 1<<N;
    vector memo(K+1, vector<ll>(N,INF));
    ll ans = INF;
    auto calc = [&](int i, int j)->ll{
        return abs(X[j]-X[i])+abs(Y[j]-Y[i])+max(0ll,Z[j]-Z[i]);
    };
    auto func = [&](auto func, int cur, ll visit, ll cost)->void{
        memo[visit][cur] = cost;
        if(visit == K-1) {
            chmin(ans, calc(cur, 0) + cost);
            return;
        }
        for(ll i=1; i<N; i++) {
            if(visit>>i & 1) continue;
            ll visit2 = visit | 1<<i;
            ll cost2 = cost + calc(cur, i);
            if(memo[visit2][i] > cost2) func(func, i, visit2, cost2);
        }
    };
    cout << ans << endl;
    return 0;
}