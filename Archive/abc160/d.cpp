#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N,X,Y;
    cin >> N >> X >> Y;
    X--, Y--;
    vector uv(N, vector<int>{});
    uv[X].push_back(Y);
    uv[Y].push_back(X);
    rep(i,N-1) {
        uv[i].push_back(i+1);
        uv[i+1].push_back(i);    
    }
    vector<ll> dcnt(N);
    rep(k, N){
        queue<int> que;
        que.push(k);    
        vector dist(N, INFi);    
        dist[k] = 0;
        while(!que.empty()) {
            int q = que.front();
            que.pop();
            for(auto nx:uv[q]){
                if(dist[nx] < INFi) continue;
                que.push(nx);
                dist[nx] = dist[q] + 1;
                dcnt[dist[nx]]++;
            }
        }
    }
    
    for(int i=1; i<N; i++) cout<<dcnt[i]/2<<endl;

    return 0;
}