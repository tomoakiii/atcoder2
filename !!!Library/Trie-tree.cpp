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
    Trie(): to(1){}
    int add(const string &s) {
        int v = 0;
        for(char c: s) {            
            if(!to[v].contains(c)) {
                int u = to.size();
                to[v][c] = u;
                to.push_back(unordered_map<char, int>());
            }            
            v = to[v][c];            
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
};

int main(){
    ll Q;
    cin >> Q;    
    Trie TR;
    vector<pair<int, string>> vp(Q);    
    vector<int> vlist(Q);
    rep(i,Q) {
        string s;
        cin>>vp[i].first>>vp[i].second;
        vlist[i] = TR.add(vp[i].second);
    }
    TR.init();
    rep(i,Q) {
        auto [t, s] = vp[i];
        if(t==1) TR.add_X(vlist[i]);
        else TR.add_Y(vlist[i]);
        cout << TR.ans << endl;
    }
    return 0;
}