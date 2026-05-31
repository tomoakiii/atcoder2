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
    ll T; cin>>T;
    while(T--){
        ll N, M, X, Y;
        cin >> N >> M >> X >> Y;
        X--, Y--;
        vector uv(N, vector<ll>{});
        rep(i,M) {
            int u,v;
            cin>>u>>v;
            u--, v--;
            uv[u].emplace_back(v);
            uv[v].emplace_back(u);
        }
        for(auto &u: uv) sort(u.begin(), u.end());
        vector<int> pre(N,INFi);
        vector<bool> visit(N);
        auto f = [&](auto f, int cur)->void{
            visit[cur] = true;
            set<int> st;
            for(auto nx: uv[cur]){
                if(visit[nx]) continue;
                pre[nx] = cur;
                f(f, nx);
            }
        };
        f(f, X);
        int id = Y;
        vector<int> ans;
        ans.push_back(Y);
        while(id != X){
            id = pre[id];
            ans.push_back(id);
        }
        reverse(ans.begin(), ans.end());
        for(auto a: ans) cout<<a+1<<" ";
        cout<<endl;
    }
    return 0;
}