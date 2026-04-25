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
    ll H,W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    ll ans=0;
    rep(h1, H) for(int h2=h1; h2<H; h2++) {
        rep(w1, W) for(int w2=w1; w2<W; w2++) {
            bool flg= true;
            for(int i=h1; i<=h2; i++) for(int j=w1; j<=w2; j++) {
                if(S[i][j] != S[h1+h2-i][w1+w2-j]) flg=false;
            }
            if(flg) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}