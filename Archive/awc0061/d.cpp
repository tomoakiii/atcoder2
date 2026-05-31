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
    ll N, M, S, T;
    cin >> N >> M >> S >> T;
    S--,T--;
    vector uv(N, vector<ll>{});
    vector A(M, vector<ll>{});

    rep(i,M) {
        int K; cin>>K;
        A[i].resize(K);
        rep(j,K){
            int a; cin>>a; a--;
            A[i][j]=a;
            uv[a].push_back(i);
        }
    }
    queue<int> que;
    vector<ll> dist(N,INF);
    que.push(S);
    dist[S]=0;
    vector<bool> used(M);
    while(!que.empty()){
        int cur=que.front();
        que.pop();
        for(auto i:uv[cur]){
            if(used[i])continue;
            used[i]=true;
            for(auto a:A[i]){
                if(chmin(dist[a],dist[cur]+1)){
                    que.push(a);
                }
            }
        }
    }
    if(dist[T]==INF) cout<<-1<<endl;
    else cout<<dist[T]<<endl;
    return 0;
}