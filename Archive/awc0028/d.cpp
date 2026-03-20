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
    vector uv(N, vector<ll>{});
    vector<set<int>> vu(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        vu[v].insert(u);
    }
    priority_queue<int, vector<int>, greater<int>> que;
    rep(i,N) if(vu[i].empty()) que.push(i);
    while(!que.empty()) {
        int c = que.top();
        cout << c+1 << " ";
        que.pop();
        for(auto nx: uv[c]) {
            vu[nx].erase(c);
            if(vu[nx].empty()) {
                que.push(nx);
            }
        }
    }
    cout<<endl;
    return 0;
}