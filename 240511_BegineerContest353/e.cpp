#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

struct trie_tree{    
    struct Node{
        unordered_map<char, int> to;
        int cnt;
        Node(): cnt(0){}
    };
    vector<Node> d;
    trie_tree(): d(1) {}
    void add(const string &s){
        int v = 0;
        for (char c: s){
            if (!d[v].to.count(c)) {
                d[v].to[c] = d.size();
                d.push_back(Node());
            }
            v = d[v].to[c];
        }
        d[v].cnt++;
    }
    ll ans;
    int dfs(int v){
        int res = d[v].cnt;
        for (auto p: d[v].to) {
            res += dfs(p.second);
        }
        if (v) ans += res*ll(res-1)/2;
        return res;
    }

    ll solve() {
        ans = 0;
        dfs(0);
        return ans;
    }

};

int main(){
    ll N;
    cin >> N;    
    trie_tree t;
    rep(i, N) {
        string s;
        cin >> s;
        t.add(s);
    }
    ll ans = t.solve();    
    cout << ans << endl;
    return 0;
}