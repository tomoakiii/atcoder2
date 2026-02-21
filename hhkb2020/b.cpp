#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    int H,W; cin>>H>>W;
    vector<string> S(H);
    ll ans=0;
    rep(i,H) cin>>S[i];
    rep(i,H)rep(j,W){
        if(S[i][j] == '#') continue;
        if(i<H-1) if(S[i+1][j] == '.') ans++;
        if(j<W-1) if(S[i][j+1] == '.') ans++;
    }
    cout<<ans<<endl;
}