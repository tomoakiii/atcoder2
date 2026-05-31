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
typedef modint998244353 mint;
/*
int main(){
    string S;
    cin >> S;
    int N=S.size();
    vector<ll> dp(4);
    dp[3] = 1;
    rep(i,N) {
        auto dp_new = dp;
        for(char c='a'; c<='d'; c++) {
            int ci = c-'a';
            int si = S[i]-'a';
            if(S[i] != c){
                dp_new[si]+=dp[ci];
            }
        }
        swap(dp,dp_new);
    }
    mint ans = 0;
    rep(i,3) ans += dp[i];
    cout<<ans.val()<<endl;
    return 0;
}
*/
int main(){
    string S;
    cin >> S;
    int N=S.size();
    vector<int> v;
    v.push_back(0);
    rep(i,N-1) {
        if(S[i]==S[i+1]) v.push_back(i+1);
    }
    mint ans=0;
    v.push_back(N);
    int M=v.size();
    rep(i,M-1) {
        ll d= v[i+1]-v[i]+1;
        ans += d*(d-1)/2;
    }
    cout<<ans.val()<<endl;
    return 0;
}