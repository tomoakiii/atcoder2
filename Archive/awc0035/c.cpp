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
    vector<ll>T(N);
    rep(i,N) cin>>T[i];
    vector uv(N, vector<ll>{});
    queue<int>que;
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        T[v]--;
        if(T[v]==-1)que.push(v);
    }
    bool flg=false;
    while(!que.empty()) {
        flg=true;
        auto q=que.front();
        que.pop();
        for(auto nx:uv[q]){
            if(T[nx]<0)continue;
            T[nx]--;
            if(T[nx]==-1)que.push(nx);
        }
    }
    if(!flg){
        cout<<-1<<endl;
        return 0;
    }
    rep(i,N) {
        if(T[i]<0)cout<<i+1<<" ";
    }
    cout<<endl;
    return 0;
}