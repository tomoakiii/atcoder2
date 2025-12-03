#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){        
    ll N, M;
    cin >> N >> M;    
    vector uv(N, vector<pair<int,ll>>{});
    rep(i,M) {
        int u,v;
        ll z;
        cin>>u>>v>>z;
        u--, v--;
        uv[u].push_back({v, z});
        uv[v].push_back({u, z});        
        
    }
    
    vector<ll> A(N);    
    rep(k, 30) {
        vector visit(2, vector<bool>(N));
        vector bit(2, vector<int>(N));
        vector<bool> done(N);
        rep(j, N) {
            int sm[2] = {0,0};
            if(done[j]) continue;
            rep(w, 2){
                queue<int> que;
                que.push(j);
                visit[w][j] = true;
                bit[w][j] = w;
                while(!que.empty()) {
                    auto cur = que.front();            
                    que.pop();
                    sm[w] += bit[w][cur];
                    for(auto [nx, x]: uv[cur]) {
                        int xb = bit[w][cur] ^ (x>>k & 1);
                        if(visit[w][nx]) {
                            if( bit[w][nx] == xb) {
                                continue;                                
                            } else {
                                cout << -1 << endl;
                                return 0;
                            }                            
                        };
                        visit[w][nx] = true;
                        bit[w][nx] = xb;
                        que.push(nx);
                    }
                }
            }   
            int w = 0;
            if(sm[0] > sm[1]) w = 1;
            queue<int> que;
            que.push(j);            
            done[j] = true;
            while(!que.empty()) {
                auto cur = que.front();            
                A[cur] |= (bit[w][cur] << k);
                que.pop();
                for(auto [nx, x]: uv[cur]) {
                    if(done[nx]) continue;
                    done[nx] = true;
                    que.push(nx);
                }
            }
        }
    }
    
    rep(i,N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
