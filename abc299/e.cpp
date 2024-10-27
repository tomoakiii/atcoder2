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
    vector uv(N, vector<int>{});
    rep(i,M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
        
    }
    ll K;
    cin >> K;
    vector<bool> bw(N, true); // all black
    vector<int> P(K), D(K);
    rep(i,K){
        int d, p;
        cin >> p >> d;
        p--;
        P[i] = p, D[i] = d;
        vector<int> dst(N, INFi);
        queue<int> que;
        vector<bool> visit(N);
        que.push(p);
        dst[p] = 0;
        while(!que.empty()){
            int q = que.front();
            que.pop();
            visit[q] = true;
            if (dst[q] < d) bw[q] = false;            
            if (dst[q] >= d) continue;
            for(auto nx: uv[q]){
                chmin(dst[nx], dst[q]+1);
                if (visit[nx]) continue;
                que.push(nx);
            }
        }
    }
    rep(i, K) {
        vector<bool> visit(N);
        bool flg = false;
        bool ng = false;
        auto f2=[&](auto f2, int cur, int dist)->void {
            visit[cur] = true;
            if (dist == D[i]) {
                if (bw[cur]) flg = true;
                return;
            }
            if (bw[cur]) {
                ng = true;
                return;
            }
            for(auto nx: uv[cur]){
                if (visit[nx]) continue;
                f2(f2, nx, dist+1);
            }
        };
        f2(f2, P[i], 0);
        if(!flg || ng) {
            cout << "No" << endl;
            return 0;
        }
    }
    bool flg = false;
    rep(i, N) if(bw[i]) flg = true;
    if(!flg) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        rep(i,N) cout<<((bw[i])?'1':'0');
        cout<<endl;
    }

    return 0;
}