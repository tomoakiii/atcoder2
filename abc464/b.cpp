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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll H,W; cin>>H>>W;
    vector<string> S(H);
    vector<bool> row(H), col(W);

    rep(i,H) {
        cin>>S[i];
    }
    vector<bool> del(H);
    rep(i,H) {
        bool flg=false;
        for(auto c:S[i]) {
            if(c=='#') flg=true;
        }
        if(!flg) {
            for(auto &c:S[i]) c='x';
            del[i]=true;
        }
        else break;
    }
    for(ll i=H-1;i>0;i--) {
        bool flg=false;
        for(auto c:S[i]) {
            if(c=='#') flg=true;
        }
        if(!flg) {
            for(auto &c:S[i]) c='x';
            del[i]=true;
        }
        else break;
    }



    rep(j,W) {
        bool flg=false;
        rep(i,H) {
            if(S[i][j]=='#') flg=true;
        }
        if(!flg) {
            rep(i,H) S[i][j]='x';
        }
        else break;
    }

    for(ll j=W-1; j>=0; j--) {
        bool flg=false;
        rep(i,H) {
            if(S[i][j]=='#') flg=true;
        }
        if(!flg) {
            rep(i,H) S[i][j]='x';
        }
        else break;
    }

    rep(i,H) {
        if(del[i]) continue;
        rep(j,W) {
            if(S[i][j]!='x')cout<<S[i][j];
        }
        cout<<endl;
    }
    return 0;
}