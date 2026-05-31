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
    ll N;
    cin >> N;
    int ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    ax--,ay--,bx--,by--;
    vector<string> S(N);
    rep(i,N) cin>>S[i];
    vector<set<pair<int,int>>> st;
    vector ind(N,vector<int>(N,-1));
    vector dist(N, vector<ll>(N,INF));
    dist[ax][ay]=0;
    bool flg = true;
    auto push=[&](int x,int y)->void{
        if(S[x][y]=='#'){
            flg=true;
        }else{
            if(flg)st.push_back(set<pair<int,int>>{});
            int id= st.size()-1;
            st[id].insert({x,y});
            ind[x][y]=id;
            flg=false;
        }
    };
    rep(i,N){
        int x=i,y=0;
        flg=true;
        while(x<N&&y<N) {            
            push(y,x);        
            x++;y++;
        }
    }
    rep(i,N-1){
        int x=0,y=i+1;
        flg=true;
        while(x<N&&y<N) {            
            push(y,x);        
            x++;y++;
        }
    }
    vector ind2(N,vector<int>(N,-1));
    auto push2=[&](int x,int y)->void{
        if(S[x][y]=='#'){
            flg=true;
        }else{
            if(flg)st.push_back(set<pair<int,int>>{});
            int id= st.size()-1;
            st[id].insert({x,y});
            ind2[x][y]=id;
            flg=false;
        }
    };
    rep(i,N){
        int x=i,y=N-1;
        flg=true;
        while(x<N&&y>=0) {            
            push2(y,x);        
            x++;y--;
        }
    }
    rep(i,N-1){
        int x=0,y=i;
        flg=true;
        while(x<N&&y>=0) {            
            push2(y,x);        
            x++;y--;
        }
    }
    queue<pair<int,int>> que;
    que.push({ax,ay});
    auto i=ind[ax][ay]; st[i].erase({ax,ay});
    auto i2=ind2[ax][ay]; st[i2].erase({ax,ay});
    while(!que.empty()){
        auto [x,y]=que.front();
        que.pop();
        ll d=dist[x][y];
        rep(kkk,2){
            auto i=ind[x][y];
            while(!st[i].empty()){
                auto [tx,ty] = *st[i].begin();
                if(chmin(dist[tx][ty], d+1)){
                    que.push({tx,ty});
                }
                st[i].erase({tx,ty});
                auto i2=ind2[x][y];
                st[i2].erase({tx,ty});
            }
            swap(ind,ind2);
        }
    }
    if(dist[bx][by]==INF) cout<<-1<<endl;
    else cout<<dist[bx][by]<<endl;
    return 0;
}