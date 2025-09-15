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
    vector<ll> cst(1<<N); 
    ll ans = INF;
    auto cost(int a, int b) -> ll {
        return abs(X[a]-X[b]) + abs(Y[a]-Y[b]) + max(0, Z[b]-Z[a]);
    };
    auto func = [](int cur, ll hist, ll cst) {
        if(hist == (1<<N) - 1) {
            chmin(ans, cst + cost(cur, 0));
        }
        for(int k=1; k<N; k++) {

        }
    };
    return 0;
}