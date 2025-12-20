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
    ll N, M;
    cin >> N >> M;
    vector uv(N, vector<pair<int,ll>>{});
    vector vu(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        ll D;
        cin>>u>>v>>D;
        u--, v--;
        uv[u].emplace_back(v,D);
        uv[v].emplace_back(u,-D);
    }
    bool flg = true;
    vector<ll> X(N, -INF);
    int k = 0;
    rep(i, N) {
        if(X[i] != -INF) continue;
        X[i] = 0;
        queue<int> que;
        que.push(i);
        while(!que.empty()){
            auto cur = que.front();
            que.pop();
            for(auto [nx, d]: uv[cur]) {
                if(X[nx] == X[cur] + d) continue;
                if(X[nx] != -INF){
                    cout<<"No"<<endl;
                    return 0;
                }
                X[nx] = X[cur] + d;
                que.push(nx);
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}