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
    string s,t; cin>>s>>t;
    ll K; cin>>K;
    ll N=s.size();
    ll M=t.size();

    auto get = [&](string S, string T)->ll{
        vector dp(N+1, vector<ll>(M+1, 0));
        rep(i,N){
            rep(j,M){
                chmax(dp[i+1][j+1], dp[i][j+1]);
                chmax(dp[i+1][j+1], dp[i+1][j]);
                if(S[i]==T[j]) {
                    chmax(dp[i+1][j+1], dp[i][j]+1);
                }
            }
        }
        return dp[N][M];
    };
    ll ans=get(s,t);
    string s2=s, t2=t, s3=s, t3=t;
    if(N>1) {
        if(s2[0]==s2[1]) s2[0]=(s2[0]=='1')?'0':'1';
    } else {
        s2 = (s2=="1")?"0":"1";
    }

    if(M>1) {
        if(t2[0]==t2[1]) t2[0]=(t2[0]=='1')?'0':'1';
    } else {
        t2 = (t2=="1")?"0":"1";
    }

    if(N>1) if(s3[N-1]==s3[N-2]) s3[N-1]=(s3[N-1]=='1')?'0':'1';
    if(M>1) if(t3[M-1]==t3[M-2]) t3[M-1]=(t3[M-1]=='1')?'0':'1';
    string s4=s2, t4=t2;
    if(N>1) if(s4[N-1]==s4[N-2]) s4[N-1]=(s4[N-1]=='1')?'0':'1';
    if(M>1) if(t4[M-1]==t4[M-2]) t4[M-1]=(t4[M-1]=='1')?'0':'1';
    if(K>=1){
        chmax(ans, get(s2,t));
        chmax(ans, get(s,t2));
        chmax(ans, get(s3,t));
        chmax(ans, get(s,t3));
    }
    if (K>=2) {
        chmax(ans, get(s4,t)); // 2+0
        chmax(ans, get(s,t4)); // 0+2
        chmax(ans, get(s2,t2)); // 1+1
        chmax(ans, get(s2,t3)); // 1+1
        chmax(ans, get(s3,t2)); // 1+1
        chmax(ans, get(s3,t3)); // 1+1
    }
    if (K>=3) {
        chmax(ans, get(s2,t4)); // 1+2
        chmax(ans, get(s3,t4)); // 1+2

        chmax(ans, get(s4,t2)); // 2+1
        chmax(ans, get(s4,t3)); // 2+1
    }
    if (K>=4) {
        chmax(ans, get(s4,t4)); // 2+2
    }
    cout<<ans<<endl;
    return 0;
}