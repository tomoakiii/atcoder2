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
typedef pair<ll,ll> pll;

int main(){
    ll T; cin>>T;
    while(T--){
        int H,W; cin>>H>>W;        
        vector<string> S(H);
        rep(i,H) cin>>S[i];
        if(H>W) {
            vector<string> S2(W, string(h, '.'));
            rep(i,H) rep(j,W) S2[j][i] = S[i][j];
            swap(S, S2);
            swap(H,W);
        }
        vector A(H, vector<ll>(W));
        vector B = A;
        vector C(H+1, vector<ll>(W+1));
        rep(i,H)rep(j,W){
            if(S[i][j] == '#') A[i][j]++;
            if(S[i][j] == '.') B[i][j]++;
        }
        rep(i,H){
            rep(j,W-1){
                A[i][j+1] += A[i][j];
                B[i][j+1] += B[i][j];
            }
        }
        rep(j,W){
            rep(i,H-1) {
                A[i+1][j] += A[i][j];
                B[i+1][j] += B[i][j];
            }
        }

        rep(i,H) rep(j,W) C[i+1][j+1] = A[i][j] - B[i][j];
        unordered_map<ll, ll> mp;
        mp[0] = 1;
        queue<pll> que;
        que.push({0,0});
        ll ans = 0;
        while(!que.empty()) {
            auto [x,y] = que.front();
            que.pop();
            ans += mp[-1 * C[x][y]];
            if(x+1 < H) que.push({x+1,y});
            if(y+1 < W) que.push({x,y+1});
            mp[C[x][y]]++;
        }
        cout<<ans<<endl;
    }

    return 0;
}