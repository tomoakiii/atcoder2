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

ll solve(){
    string S; ll K;
    cin>>S>>K;
    ll N=S.size();
    vector<int> val(N,-1);
    auto cnt = [&](string T)->ll{
        int id = 0;
        rep(i,N-2){
            if(T[i]=='A' && T[i+1]=='B' && T[i+2]=='C') {
                val[i]=val[i+1]=val[i+2]=id++;
            }
        }
        return ret;
    };
    vector<bool> visit(N);
    ll M = 3*K+1;
    vector dp(N+1, vector(4, vector(M, vector<ll>(2, -INF))));
    dp[0][3][0][0] = 0;
    ll r = cnt(S);
    for(auto &c:S) if(c>'C') c='D';
    rep(i,N){
        if(S[i]=='A' && S[i+1]=='B' && S[i+2]=='C') {

        }

    }
    ll ans = INF;
    rep(k,3*K+1){
        rep(j,4) if(dp[N][j][k] == r+K) {
            chmin(ans,k);
        }
    }
    if(ans<INF) return ans;
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    rep(i,N) {
        cout <<solve() << endl;
    }
    return 0;
}