// https://atcoder.jp/contests/abc403/tasks/abc403_e
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
struct Trie{
    ll ans = 0;
    vector<unordered_map<char, int>> to;
    vector<bool> isX;
    vector<int> isY;
    vector<ll> cnt;
    Trie(): to(1){}
    int add(const string &s) {
        int v = 0;
        cnt.resize(1e6);
        cnt[0] = INF;
        for(char c: s) {
            if(!to[v].contains(c)) {
                int u = to.size();
                to[v][c] = u;
                to.push_back(unordered_map<char, int>());
            }
            v = to[v][c];
            cnt[v]++;
        }
        return v;
    }

    void init(){
        int m = to.size();
        isX.resize(m);
        isY.resize(m);
    }

    void add_X(int v) {
        if(isY[v] > 0) {
            ans -= isY[v];
            isY[v] = 0;
        }
        if(isX[v]) return;
        isX[v] = true;
        for(auto [c, nx]: to[v]) add_X(nx);
    }

    void add_Y(int v) {
        if(isX[v]) return;
        isY[v]++;
        ans++;
    }

    void solve(int N){
        ll ans = 0;
        ll x = 0;
        auto dfs = [&](auto dfs, int cur, int d)->bool{
            bool flg = false;
            if(cnt[cur]==1){
                ans += d;
                x++;
                return true;
            }
            for(char c='a'; c<='z'; c++){
                if(!to[cur].contains(c))continue;
                int nx = to[cur][c];
                flg |= dfs(dfs, nx, d+1);
            }
            return flg;
        };
        dfs(dfs,0,0);
        if(x==N) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
};

int main(){
    ll N; cin>>N;
    Trie TR;
    rep(i,N) {
        string s; cin>>s;
        TR.add(s);
    }
    TR.solve(N);
    return 0;
}