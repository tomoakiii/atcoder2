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
    int H,W,K; cin>>H>>W>>K;
    char c1,c2; cin>>c1>>c2;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    rep(i,H*K) {
        rep(j,W*K) cout << (S[i/K][j/K]=='#'?c1:c2);
        cout << endl;
    }
    return 0;
}