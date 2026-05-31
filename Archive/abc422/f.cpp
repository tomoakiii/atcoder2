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
typedef pair<ll, int> pli;
int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> W(N);
    rep(i,N) cin>>W[i];    
    vector uv(N, vector<int>{});
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);        
    }
    vector<ll> wei(2*N, INF), gas(2*N, INF);
    queue<pli> que;
    wei[0] = W[0], gas[0] = 0;
    wei[N] = W[0], gas[N] = 0;
    que.push({W[0],0});
    que.push({0,N});
    while(!que.empty()) {
        auto [v,q] = que.front();
        que.pop();
        if(q < N && wei[q] < v) continue;
        if(q >= N && gas[q] < v) continue;
        for(auto nx: uv[q%N]) {
            ll nwei = wei[q] + W[nx];
            ll ngas = gas[q] + wei[q];
            if(wei[nx] > nwei || (wei[nx] == nwei && gas[nx] > ngas) ) {
                wei[nx] = nwei, gas[nx] = ngas;
                que.push({wei[nx], nx});
            }
            nx += N;
            if(gas[nx] > ngas || (gas[nx] == ngas && wei[nx] > nwei)) {
                wei[nx] = nwei, gas[nx] = ngas;                
                que.push({gas[nx], nx});
            }
        }
    }
    rep(i,N) cout << gas[i+N] << endl;
    return 0;
}