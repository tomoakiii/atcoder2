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
typedef pair<int,int> pii;
typedef pair<pii, int> piii;
typedef pair<ll,ll> pll; // depth + direction
typedef pair<pll, pii> pp;
int main(){
    int T; cin>>T;
    map<pair<int, int>, char> mp2;
    mp2[{0,2}] = 'A';
    mp2[{2,0}] = 'A';
    mp2[{1,3}] = 'A';
    mp2[{3,1}] = 'A';

    mp2[{2,1}] = 'B';
    mp2[{1,2}] = 'B';
    mp2[{0,3}] = 'B';
    mp2[{3,0}] = 'B';

    mp2[{2,3}] = 'C';
    mp2[{3,2}] = 'C';
    mp2[{0,1}] = 'C';
    mp2[{1,0}] = 'C';

    int rev[] = {2,3,0,1};
    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};

    while(T--){
        int H, W;
        cin>>H>>W;
        vector<string> S(H);
        rep(i,H) cin>>S[i];
        vector dp(H, vector(W, vector<ll>(4, INF)));
        // 0:→→, 1:↓↓, 2:←←, 3:↑↑
        dp[0][0][2] = 0;
        priority_queue< pp, vector<pp>, greater<pp> > que;
        que.push({{0,2}, {0,0}});

        while(!que.empty()) {
            auto [depdir, hw] = que.top();
            auto [dep,dir] = depdir;
            auto [h1, w1] = hw;
            que.pop();

            if(dp[h1][w1][dir] < dep) continue;

            auto isok = [&](int h, int w)->bool{
                return !(h >= H || h < 0 || w >= W || w < 0);
            };


            rep(k,4) {
                if(k==dir) continue;
                char c = mp2[{dir,k}];
                int x = (c==S[h1][w1]) ? 0 : 1;
                if(!chmin(dp[h1][w1][k], dep + x)) continue;
                int nh = h1 + dy[k];
                int nw = w1 + dx[k];
                if(!isok(nh,nw)) continue;
                int rk = rev[k];
                if (!chmin(dp[nh][nw][rk], dp[h1][w1][k])) continue;
                que.push({{dp[nh][nw][rk], rk}, {nh, nw}});

            }
        }
        cout<<dp[H-1][W-1][0]<<endl;
    }
    return 0;
}