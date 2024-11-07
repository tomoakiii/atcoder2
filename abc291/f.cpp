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
    vector uv(2, vector(N, vector<int>{}));
    
    rep(i,N) {
        string S;
        cin>>S;
        rep(j,M) {
            if(S[j]=='1') {
                uv[0][i].emplace_back(j+i+1);
                uv[1][j+i+1].emplace_back(i);
            }
        }
    }

    vector dist(2, vector<ll>(N, INF));
    dist[0][0] = 0, dist[1][N-1] = 0;
    priority_queue<pli, vector<pli>, greater<pli>> que;    
    int st[2] = {0, N-1};

    rep(i, 2) {    
        for (auto j: uv[i][st[i]]) que.push({1, j});
        while(!que.empty()) {
            auto [d, j] = que.top();
            que.pop();
            if(dist[i][j] < d) continue;
            dist[i][j] = d;
            for(auto k: uv[i][j]) {
                if(dist[i][k] > d+1) que.push({d+1, k});
            }
        }
    }
    for(int i=1; i<N-1; i++) {
        ll d = INF;
        rep(j, M-1) {
            int pre = i-j-1;
            if(pre<0) continue;
            for (auto k: uv[0][pre]) {
                if (k <= i) continue;
                chmin(d, 1 + dist[0][pre] + dist[1][k]);
            }
        }
        if(d==INF) d = -1;
        cout<<d<<" ";
    }
    cout << endl;
    return 0;
}