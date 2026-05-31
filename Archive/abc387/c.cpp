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
    ll l,r;
    cin >> l >> r;

    auto f = [&](auto f, int cur, ll lmt, int isany, string &s) -> ll{
        ll ret;
        ll p = (s[cur]-'0');
        if(cur == s.size()-1){
            if(isany == 1) ret = lmt;
            else ret = min(lmt, p+1);
        } else {
            if(isany == 1) ret = lmt * f(f,cur+1,lmt,1,s);
            else if(p<lmt) ret = p*f(f,cur+1,lmt,1,s) + f(f,cur+1,lmt,0,s);
            else ret = lmt*f(f,cur+1,lmt,1,s);
        }
        return ret;
    };
    
    auto solve = [&](ll nm)->ll{
        if(nm < 10) return 0;
        string S = to_string(nm);
        ll l=0;
        string tmp = "";
        for(int d=1; d<S.size(); d++) {
            tmp = tmp + '9';
            if(d < (S.size() - 1)){
                for(int k=1; k<=9; k++) {
                    l += f(f, 0, k, 1, tmp);
                }
            } else {
                for(int k=1; k<(S[0]-'0'); k++) {
                    l += f(f, 0, k, 1, tmp);
                }
            }
        }
        ll p = S[0] - '0';
        reverse(S.begin(), S.end());        
        S.pop_back();
        reverse(S.begin(), S.end());
        l += f(f, 0, p, 0, S);
        return l;
    };
    cout << solve(r) - solve(l-1) << endl;
    return 0;
}