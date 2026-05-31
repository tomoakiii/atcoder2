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
    ll X,Y; cin>>X>>Y;
    if(abs(X-Y)<=1) cout<<"Brown"<<endl;
    else cout<<"Alice"<<endl;
    /*
    vector memo(X,vector<int>(X,-1));
    rep(i,X)rep(j,X) memo[i][j]=-1;
    queue<pair<int,int>> que;
    rep(i,2)rep(j,2) {
        memo[i][j]=0;
    }
    auto dfs = [&](auto dfs, int i, int j)->int{
        if(memo[i][j]!=-1) return memo[i][j];
        for(int k=1; i-2*k>=0; k++) {
            if(dfs(dfs, i-2*k, j+k) == 0) {
                memo[i][j]=1;
                return 1;
            }
        }
        for(int k=1; j-2*k>=0; k++) {
            if(dfs(dfs, i+k, j-2*k) == 0) {
                memo[i][j]=1;
                return 1;
            }
        }
        memo[i][j]=0;
        return 0;
    };
    rep(i,X/2) rep(j,X/2) {
        dfs(dfs, i, j);
    }
    rep(i,X)rep(j,Y) memo[i][j]++;
    rep(i,X){
        rep(j,X) cerr<<memo[i][j]<<" ";
        cerr<<endl;
    }
    */
    return 0;
}