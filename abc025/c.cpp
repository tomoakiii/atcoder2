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

vector G(3, vector<int>(3));
map<vector<vector<int>>, pair<ll,ll>> mp;
pair<ll,ll> dfs();
pair<ll,ll> dfs2();

pair<ll,ll> dfs(){
    if(mp.contains(G)) return mp[G];
    pair<ll,ll> mx = {-INF,-INF};
    rep(i,3) rep(j,3) if(G[i][j]==-1){
        G[i][j] = 1;
        pair<ll,ll> sc = dfs2();
        if(mx.first < sc.first) mx = sc;
        else if (mx.first == sc.first) {
            if(mx.second > sc.second) {
                mx = sc;
            }
        }
        G[i][j] = -1;
    }
    mp[G] = mx;
    return mp[G];
};

pair<ll,ll> dfs2(){
    if(mp.contains(G)) return mp[G];
    pair<ll,ll> mx = {-INF,-INF};
    rep(i,3) rep(j,3) if(G[i][j]==-1){
        G[i][j] = 0;
        pair<ll,ll> sc = dfs();
        if(mx.second < sc.second) mx = sc;
        else if (mx.second == sc.second) {
            if(mx.first > sc.first) {
                mx = sc;
            }
        }
        G[i][j] = -1;
    }
    mp[G] = mx;
    return mp[G];
};


int main(){
    vector B(2, vector<ll>(3));
    vector C(3, vector<ll>(2));
    rep(i,2) rep(j,3) cin>>B[i][j];
    rep(i,3) rep(j,2) cin>>C[i][j];
    vector<ll> ORD(9,1);
    rep(i,4) ORD[i] = 0;
    do{
        rep(i,3) rep(j,3) {
            if(ORD[i*3+j]==1) G[i][j]=1;
            else G[i][j]=0;
        }
        pair<ll,ll> score = {0,0};
        rep(i,2) rep(j,3) if(G[i+1][j] == G[i][j]) {
            score.first+=B[i][j];
        } else {
            score.second+=B[i][j];
        }
        rep(i,3) rep(j,2) if(G[i][j+1] == G[i][j]) {
            score.first+=C[i][j];
        } else {
            score.second+=C[i][j];
        }
        mp[G] = score;
        rep(i,3)rep(j,3) {
            int g = G[i][j];
            G[i][j] = -1;
            mp[G] = score;
            G[i][j] = g;
        }
    }while(next_permutation(ORD.begin(),ORD.end()));

    rep(i,3)rep(j,3)G[i][j]=-1;
    /*
    G[0] = {0,1,0};
    G[1] = {1,1,0};
    G[2] = {1,0,1};
    */
    auto score = dfs();
    
    cout << score.first << endl << score.second << endl;
    return 0;
}