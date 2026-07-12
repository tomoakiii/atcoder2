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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M;
    cin >> N >> M;
    vector<int> PC(N,-1);
    rep(i,N) {
        int p,c; cin>>p>>c;
        if(p==1) PC[i]=c-1;
    }

    vector uv(N,vector<pair<int,int>>{});
    rep(i,M){
        int u,v,k; cin>>u>>v>>k;
        u--,v--,k--;
        uv[u].emplace_back(v,k);
    }
    vector<bool> own(N);
    vector<bool> visit(N);

    map<int, vector<int>> mp;
    queue<int> que;
    que.push(0);
    visit[0]=true;
    while(!que.empty()){
        auto q = que.front();
        que.pop();
        int c = PC[q];
        if(c>-1){
            own[c] = true;
            if(mp.contains(c)) {
                for(auto i:mp[c]) {
                    if(!visit[i]){
                        visit[i] = true;
                        que.push(i);
                    }
                }
            }
            mp.erase(c);
        }
        for(auto [nx,k]: uv[q]){
            if(own[k]) {
                if(visit[nx])continue;
                visit[nx] = true;
                que.push(nx);
            }else{
                mp[k].push_back(nx);
            }
        }
    }
    if(visit[N-1]) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}