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
    ll H,W; cin>>H>>W;
    vector<string> S(H);
    rep(i,H) cin>>S[i];
    rep(i,H) {
        int cnt = 0;
        rep(j,W) {
            cnt += (S[i][j]=='#')?1:0;
        }
        if(cnt==0){
            rep(j,W) S[i][j]='?';
        }
    }
    rep(j,W) {
        int cnt = 0;
        rep(i,H) {
            cnt += (S[i][j]=='#')?1:0;
        }
        if(cnt==0){
            rep(i,H) S[i][j]='?';
        }
    }
    rep(i,H) {
        bool flg = false;
        rep(j,W) {
            if(S[i][j]!='?') {
                cout<<S[i][j];
                flg = true;
            }
        }
        if(flg) cout<<endl;
    }

    return 0;
}