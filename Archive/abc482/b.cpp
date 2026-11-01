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
    vector<string > S(5);
    rep(i,5) cin>>S[i];
    ll ans=INF;
    for(auto s:S){
        ll cnt=0;
        for(auto c:s)if(c=='o')cnt++;
        chmin(ans, 5-cnt);
    }
    rep(j,5){
        ll cnt=0;
        rep(i,5) {
            char c=S[i][j];
            if(c=='o')cnt++;
        }
        chmin(ans, 5-cnt);
    }

    {
        ll cnt=0;
        rep(i,5){
            char c=S[i][i];
            if(c=='o')cnt++;
        }
        chmin(ans, 5-cnt);
    }


    {
        ll cnt=0;
        rep(i,5){
            char c=S[i][4-i];
            if(c=='o')cnt++;
        }
        chmin(ans, 5-cnt);
    }

    cout << ans << endl;

    return 0;
}