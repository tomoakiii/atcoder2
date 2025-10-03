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
ll dp[20][10][2];

int main(){
    ll l,r;
    cin >> l >> r;
    string L = to_string(l-1);
    string R = to_string(r);

    auto f = [&](auto f, int cur, ll lmt, int isany, string &s) -> ll{
        if(dp[cur][lmt][isany] != -1) return dp[cur][lmt][isany];
        ll p = (s[cur]-'0');
        if(cur == s.size()-1){
            if(isany == 1) dp[cur][lmt][isany] = lmt;
            else dp[cur][lmt][isany] = min(lmt, p);
        } else {
            if(isany == 1) dp[cur][lmt][isany] = lmt * f(f,cur+1,lmt,1,s);
            else if(p<lmt) dp[cur][lmt][isany] = p*f(f,cur+1,lmt,1,s) + f(f,cur+1,lmt,0,s);
            else dp[cur][lmt][isany] = (p+1)*f(f,cur+1,lmt,1,s);
        }
        return dp[cur][lmt][isany];
    };

    rep(i,20) rep(j,10) rep(k,2) dp[i][j][k] = -1;
    
    auto solve = [&](string S)->ll{
        ll l=0;
        for(int i=1; i<(S[0]-'0'); i++) l += f(f,0,i,1,S);
        l+=f(f,0,(S[0]-'0'),0,L);
        return l;
    };
    cout << solve(R) - solve(L) << endl;
    return 0;
}