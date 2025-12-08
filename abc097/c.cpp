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
    vector<map<char, int>> to;
    Trie(): to(1){}
    int add(const string &s) {
        int v = 0;
        for(char c: s) {
            if(!to[v].contains(c)) {
                int u = to.size();
                to[v][c] = u;
                to.push_back(map<char, int>());
            }
            v = to[v][c];
        }
        return v;
    }
    void init(int K){
        bool flg = false;
        int k = 0;
        auto func = [&](auto func, int v0, string cur)->void{
            if(flg) return;
            for(auto [c,v]: to[v0]) {
                if(flg) return;
                cur.push_back(c);
                k++;
                if(k == K) {
                    cout<<cur<<endl;
                    flg = true;
                    return;
                } else {
                    func(func, v, cur);
                }
                cur.pop_back();
            }
        };
        rep(i, to.size()){
            func(func, i, "");
        }
    }
};

int main(){
    Trie TR;
    string S;
    cin>>S;
    rep(i,S.size()) {
        int mn = S.size() - i;
        TR.add(S.substr(i, min(6, mn)));
    }
    int K; cin>>K;
    TR.init(K);
    return 0;
}