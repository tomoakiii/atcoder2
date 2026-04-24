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
    ll N;
    cin >> N;
    int flg = (N%2==0);
    deque<ll> A(N);
    rep(i,N) cin>>A[i];
    vector dp(N, vector<pair<ll,ll>>(N));
    vector visit(N, vector<bool>(N));
    auto dfs = [&](auto dfs, int l, int r, bool turn)->void{
        visit[l][r]=true;
        if(l == r) {
            if(turn) dp[l][r] = {A[l], 0};
            else dp[l][r] = {0, A[l]};
            return;
        } else {
            if(!visit[l+1][r]) dfs(dfs, l+1, r, !turn);
            if(!visit[l][r-1]) dfs(dfs, l, r-1, !turn);
            auto [x0, y0] = dp[l+1][r];
            auto [x1, y1] = dp[l][r-1];
            if(turn) {
                x0 += A[l];
                x1 += A[r];
                if(x0 - y0 > x1 - y1) dp[l][r] = {x0, y0};
                else dp[l][r] = {x1, y1};
            } else {
                y0 += A[l];
                y1 += A[r];
                if(y0 - x0 > y1 - x1) dp[l][r] = {x0, y0};
                else dp[l][r] = {x1, y1};
            }
        }
    };
    dfs(dfs, 0, N-1, true);
    auto [sm0, sm1] = dp[0][N-1];
    cout<<sm0<<" "<<sm1<<endl;
    return 0;
}