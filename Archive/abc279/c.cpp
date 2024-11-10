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
    ll H, W;
    cin >> H >> W;
    map<string, int> S, T;
    vector<string> Si(H), Ti(H);
    rep(i,H) cin >> Si[i];
    rep(i,H) cin >> Ti[i];    
    rep(j, W) {
        string s="", t="";
        rep(i,H) {
            s += Si[i][j];
            t += Ti[i][j];
        }
        S[s]++;
        T[t]++;
    }
    auto it = T.begin();
    bool ans = true;
    for(auto s:S) {
        if ((*it).first != s.first || (*it).second != s.second) ans = false;
        it++;
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}