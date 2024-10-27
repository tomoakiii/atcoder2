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
    }
    vector dst(K, vector<int>(N, INFi));
    rep(i,K){
        queue<int> que;
        que.push(P[i]);
        dst[i][P[i]] = 0;
        while(!que.empty()){
            int q = que.front();
            que.pop();
            if (dst[i][q] < D[i]) bw[q] = false;            
            if (dst[i][q] >= D[i]) continue;
            for(auto nx: uv[q]){
                if (dst[i][nx] < INFi) continue;
                dst[i][nx] = dst[i][q]+1;
                que.push(nx);
            }
        }
    }
    rep(i, K) {
        bool flg = false;
        rep(j,N) {
            if (dst[i][j] == D[i] && bw[j]) flg = true;
        }
        if (!flg) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i,N) cout<<((bw[i])?'1':'0');
    cout<<endl;

    return 0;
}