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
    ll N,R; cin>>N>>R;
    ll M = 100000;
    vector<mint> fact(M+1,1);
    for(ll i=2; i<=M; i++) {
        fact[i] = fact[i-1]*i;
    }
    vector<mint> i_fact(M+1,1);
    i_fact[M] = (mint)1 / fact[M];
    for(ll i=M-1; i>=1; i--) {
        i_fact[i] = i_fact[i+1] * (i+1);
    }
    mint ans = fact[N];
    ans *= i_fact[R];
    ans *= i_fact[N-R];
    cout << ans.val() << endl;
    return 0;
}