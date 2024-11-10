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
    ll T, N, M;
    cin >> T;
    vector<int> C(2001);
    vector uv(2001, vector(2, vector<int>(2001)));
    while(T--){
        cin >> N >> M;
        uv.clear();
        uv.resize(2001, vector(2, vector<int>{}));
        rep(i,N) {
            cin >> C[i];
        }
//        dsu ds(N);
        rep(i,M){
            int u, v;
            cin >> u >> v;
            u--, v--;
            uv[u][C[v]].emplace_back(v);
            uv[v][C[u]].emplace_back(u);
            //ds.merge(u,v);
        }
//        if(ds.leader(0) != ds.leader(N-1)) {
//            cout << "-1" << endl;
//           continue;
//        }
        queue<pair<int, int>> que;
        que.push({0, N-1});
        vector mp(2001, vector<int>(2001, INFi));
        mp[0][N-1] = 0;
        while(!que.empty()) {
            auto [q1, q2] = que.front();
            que.pop();
            for(int i1=0, i2=1; i1<2; i1++, i2--){            
                for(auto s1: uv[q1][i1]) {
                    for (auto s2: uv[q2][i2]) {
                        if (mp[s1][s2] < INFi) continue;
                        mp[s1][s2] = mp[q1][q2] + 1;
                        que.push({s1, s2});
                    }
                }
            }
            if(mp[N-1][0] < INFi) break;
        }
        if (mp[N-1][0] == INFi) {
            cout << "-1" << endl;
        } else {
            cout << mp[N-1][0] << endl;
        }
    }
    return 0;
}