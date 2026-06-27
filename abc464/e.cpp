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
    ll H,W,Q; cin>>H>>W>>Q;
    vector<tuple<ll,ll,char>> vec(Q);
    rep(i,Q) {
        ll r,c; char x;
        cin>>r>>c>>x;
        r--,c--;
        vec[i]=make_tuple(r,c,x);
    }
    vector<string> G(H, string(W, '?'));
    for(int i=Q-1; i>=0; i--){
        auto [r,c,x] = vec[i];
        queue<pair<int,int>> que;
        que.push({r,c});
        if(G[r][c]!='?') continue;
        G[r][c]=x;
        while(!que.empty()){
            auto [i,j]=que.front();
            que.pop();
            if(i>0) {
                if(G[i-1][j] == '?') {
                    G[i-1][j] = x;
                    que.push({i-1,j});
                }
            }
            if(j>0) {
                if(G[i][j-1] == '?') {
                    G[i][j-1] = x;
                    que.push({i,j-1});
                }
            }
        }
    }
    rep(i,H) rep(j,W) if(G[i][j]=='?') G[i][j]='A';
    rep(i,H) cout<<G[i]<<endl;
    return 0;
}