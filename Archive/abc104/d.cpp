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
typedef modint1000000007 mint;
int main(){
    string S; cin>>S;
    ll N=S.size();
    mint nmq=1;
    vector<mint> dp(3);
    rep(i,N){
        char c=S[i];
        vector<mint> dp_new = dp;
        if(c=='A') {
            dp_new[0]+=nmq;
        } else if (c=='B') {
            dp_new[1]+=dp[0];
        } else if (c=='C') {
            dp_new[2]+=dp[1];
        } else {
            dp_new[0] = dp[0]*3 + nmq;
            dp_new[1] = dp[1]*3 + dp[0];
            dp_new[2] = dp[2]*3 + dp[1];
            nmq*=3;
        }
        swap(dp,dp_new);
        //cerr<<dp[0].val()<<" "<<dp[1].val()<<" "<<dp[2].val()<<endl;
    }
    cout << dp[2].val() << endl;
    return 0;
}

/*
????

A,B,C

AA, BA, CA, AB, BB, CB, AC, BC, CC
6 1 0

AAA BAA CAA ABA BBA CBA ACA BCA CCA
AAB BAB CAB ABB BBB CBB ACB BCB CCB
AAC BAC CAC ABC BBC CBC ACC BCC CCC

27 (6*3 + 9)
9 (1*3+6)

*/