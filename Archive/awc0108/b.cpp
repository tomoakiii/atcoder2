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
const string T = "sayounara";

void solve(){
    string s;
    cin >> s;
    vector dp(s.size()+1, vector<ll>(T.size()+1));
    rep(i,s.size()){
        rep(j, T.size()){
            chmax(dp[i+1][j+1], dp[i+1][j]);
            chmax(dp[i+1][j+1], dp[i][j+1]);
            if(s[i]==T[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
        }
    }
    if(dp[s.size()][T.size()] == T.size()) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    ll N;
    cin >> N;

    rep(i,N){
        solve();
    }
    return 0;
}