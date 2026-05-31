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
    ll N,M;
    cin>>N>>M;
    vector<ll> P(N),V(N);
    rep(i,N) cin>>P[i]>>V[i];

    vector dp(N+1, vector<ll>(M+1));
    rep(i,N) {
        rep(j,M+1) {
            chmax(dp[i+1][j], dp[i][j]);
            ll nj = j+P[i];
            if(nj > M) continue;
            chmax(dp[i+1][nj], dp[i][j] + V[i]);
        }
    }
    vector<int> cur;
    cur.push_back(M);
    string ans(N, '-');
    for(int i = N-1; i>=0; i--) {
        vector<int> nx;
        bool pos=false, neg=false;
        for(auto c: cur) {
            if(dp[i+1][c] == dp[i][c]) {
                nx.push_back(c);
                neg = true;
            }
            int nc = c - P[i];
            if(nc >= 0 && dp[i+1][c] == dp[i][nc] + V[i]) {
                nx.push_back(nc);
                pos = true;
            }
        }
        if(!pos) ans[i] = 'C';
        else if(neg) ans[i] = 'B';
        else ans[i] = 'A';
        sort(nx.begin(), nx.end());
        nx.erase(unique(nx.begin(), nx.end()), nx.end());
        swap(nx, cur);
    }
    cout << ans << endl;
    return 0;
}