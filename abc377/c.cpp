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
    set<pair<ll, ll>> AB;
    int dy[8] = {2, 1, -1, -2, -2, -1,  1,  2};
    int dx[8] = {1, 2,  2,  1, -1, -2, -2, -1};
    rep(i,M) {
        int a,b;
        cin>>a>>b;
        a--, b--;
        AB.insert({a,b});        
        rep(k, 8){
            pair<ll, ll> nx = {a+dy[k], b+dx[k]};
            if(nx.first < 0 || nx.first >= N || nx.second < 0 || nx.second >= N) {
                continue;
            }            
            AB.insert(nx);
        }
    }
    
    cout << N*N - ((ll)AB.size()) << endl;
    return 0;
}