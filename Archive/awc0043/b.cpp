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
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,int>> R(N);
    rep(i,N) {
        cin>>R[i].first;
        R[i].second=i;
    }
    sort(R.rbegin(),R.rend());
    vector uv(N,vector<int>{});
    vector<bool> visit(N);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        uv[u].emplace_back(v);
        uv[v].emplace_back(u);
    }
    rep(i,N) sort(uv[i].begin(),uv[i].end());
    for(auto [r,i]:R) {
        if(visit[i])continue;
        for(auto j : uv[i]) {
            if(visit[j])continue;
            visit[j]=true;
            visit[i]=true;
            if(i==0) {
                cout<<j+1<<endl;
                return 0;
            }else if(j==0){
                cout<<i+1<<endl;
                return 0;
            }
            break;
        }
    }

    return 0;
}