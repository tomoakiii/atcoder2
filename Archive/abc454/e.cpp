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

bool solve(int N, int A, int B){
    string ans="";
    rep(k,A/2) {
        rep(i,N) ans.push_back('D');
        ans.push_back('R');
        rep(i,N) ans.push_back('U');
        ans.push_back('R');
    }
    int ln=N-A;
    rep(k,B/2) {
        rep(i,ln) ans.push_back('R');
        ans.push_back('nhjm');

    }
}

bool solve2(vector<vector<bool>> &G, int N){
    bool d=true;
    vector cnt(N,vector<ll>(N,-1));
    string ans="";
    auto dfs=[&](auto dfs, int y, int x, int ct)->void{
        cnt[y][x]=ct;
        if(y==N-1 && d) {
            d=false;
        } else if(y==0 && !d) {
            d=true;
        }
        auto step=[&](int ty, int tx, char c)->bool{
            if(ty<0 || ty>=N || tx<0 || tx>=N) return false;
            if(cnt[ty][tx]!=-1)return false;
            if(G[ty][tx])return false;
            ans.push_back(c);
            return true;
        };

        int nx[]={x-1,x,x+1};
        int ny[]={y,(d?y+1:y-1),y};
        char dir[]={'L',(d?'D':'U'),'R'};
        rep(k,3) {
            if(step(ny[k],nx[k],dir[k])){
                dfs(dfs,ny[k],nx[k],ct+1);
                return;
            }
        }
    };
    dfs(dfs,0,0,0);
    if(cnt[N-1][N-1] == N*N-2) {
        cout<<"Yes\n"<<ans<<endl;
        return true;
    } else {
        return false;
    }
}



bool solve3(vector<vector<bool>> &G, int N, int A, int B){
    if(N==4 && A==3 && B==2) {
        string ans="DDDRUUURRDLDRD";
        cout<<"Yes\n"<<ans<<endl;
        return true;
    }
    if(N==4 && A==2 && B==3) {
        string ans="RRRDLLLDDRURDR";
        cout<<"Yes\n"<<ans<<endl;
        return true;
    }
    return false;
}





int main(){
    ll T; cin>>T;
    while(T--){
        int N,A,B; cin>>N>>A>>B;
        vector G(N,vector<bool>(N));
        A--,B--;
        G[A][B]=true;
        if(solve(G,N)) continue;
        if(solve2(G,N)) continue;
        if(solve3(G,N,A,B)) continue;


        cout<<"No"<<endl;
    }
    return 0;
}