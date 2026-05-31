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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector mp(N, vector<pair<ll,ll>>(N,{-INF,-INF}));
    auto dfs = [&](auto dfs, int a, int b, bool turn)->pair<ll,ll>{
        if(a==b) {
            if(turn) mp[a][b] = {A[a],0};
            else mp[a][b] = {0,A[a]};
            return mp[a][b];
        }
        if(mp[a+1][b].first==-INF) mp[a+1][b]=dfs(dfs,a+1,b,!turn);
        if(mp[a][b-1].first==-INF) mp[a][b-1]=dfs(dfs,a,b-1,!turn);
        if(turn) {
            ll x = mp[a+1][b].first + A[a] - mp[a+1][b].second;
            ll y = mp[a][b-1].first + A[b]  - mp[a][b-1].second;
            if(x > y) {
                mp[a][b] = mp[a+1][b];
                mp[a][b].first += A[a];
            } else {
                mp[a][b] = mp[a][b-1];
                mp[a][b].first += A[b];
            }
        } else {
            ll x = mp[a+1][b].second + A[a] - mp[a+1][b].first;
            ll y = mp[a][b-1].second + A[b]  - mp[a][b-1].first;
            if(x > y) {
                mp[a][b] = mp[a+1][b];
                mp[a][b].second += A[a];
            } else {
                mp[a][b] = mp[a][b-1];
                mp[a][b].second += A[b];
            }
        }
        return mp[a][b];
    };
    dfs(dfs, 0, N-1, true);
    cout<<mp[0][N-1].first - mp[0][N-1].second<<endl;
    return 0;
}