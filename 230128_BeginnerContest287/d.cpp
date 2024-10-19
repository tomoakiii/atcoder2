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
    string S, T;
    cin >> S >> T;

    vector<bool> jdg(T.size()+1);
    bool flg= true;
    rep(i, T.size()) {
        if (S[i] != T[i] && S[i] !='?' && T[i] != '?') flg = false;
        jdg[i+1] = flg;
    }
    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());
    reverse(jdg.begin(), jdg.end());
    flg = true;
    rep(i, T.size()) {
        if (S[i] != T[i] && S[i] !='?' && T[i] != '?') flg = false;
        jdg[i] = flg;
    }
    reverse(jdg.begin(), jdg.end());
    for(auto j: jdg) {
        if (!j) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}