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
    int N, M, K;
    cin >> N >> M >> K;
    vector uv(N, vector<pair<int, bool>>{});
    vector<bool> isS(N);
    rep(i, M) {
        int u,v,a;
        cin >> u >> v >> a;
        u--, v--;
        bool flg = (a==1);
        uv[u].push_back({v, flg});
        uv[v].push_back({u, flg});
    }
    rep(i,K) {
        int s;
        cin >> s;
        s--;
        isS[s] = true;
    }
    map<pair<int, bool>, bool> visit;
    ll mn = INF;

    queue<tuple<int, bool, ll>> que;
    que.push({0, true, 0});
    visit[{0, true}] = true;
    while(!que.empty()) {
        auto [cur, f, cnt] = que.front();
        que.pop();
        if (cur == N-1) {
            chmin(mn, cnt);
            break;
        }        
        for(auto [nx, f2] : uv[cur]) {
            if (f2 == f) {
                if (!visit[{nx, f}]) {
                    visit[{nx, f}] = true;
                    que.push({nx, f, cnt+1});
                }
            }
            if (isS[cur] && f2 != f) {
                if (!visit[{nx, !f}]) {
                    visit[{nx, !f}] = true;
                    que.push({nx, !f, cnt+1});
                }
            }
        }
    }
    
    if(mn == INF) mn = -1;
    cout << mn << endl;
    return 0;
}