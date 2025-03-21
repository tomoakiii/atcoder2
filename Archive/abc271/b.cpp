#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector L(N, vector<ll>{});
    rep(i, N) {
        int ll;
        cin >> ll;
        L[i].resize(ll);
        rep(j, ll) cin >> L[i][j];
        
    }
    while(Q--){
        int s,t;
        cin >> s >> t;
        s--, t--;
        cout << L[s][t] << "\n";
    }
    return 0;
}