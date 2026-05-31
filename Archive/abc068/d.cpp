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
    ll K; cin>>K;
    ll N = 50;
    cout<<N<<endl;
    ll ans = (N-1) + K/N;
    ll rm = K%N;
    rep(i,rm) {
        cout << ans + N - (rm-1) << " ";
    }
    for(int i=rm; i<N; i++) {
        cout << ans - rm << " ";
    }
    cout<<endl;
    return 0;
}