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
    ll K,N;
    cin >> K >> N;
    vector V(N, vector<int>{});
    vector<string> W(N);
    rep(i,N){
        ll v; cin>>v>>W[i];
        while(v){
            V[i].push_back(v%10 - 1);
            v/=10;
        }
        reverse(V[i].begin(), V[i].end());
    }
    ll p1 = 1;
    rep(i,K) p1 *= 3;
    rep(k, p1) {
        vector<int> sz(K);
        ll kt = k;
        rep(i, K) {
            int r = kt % 3;
            kt /= 3;
            sz[i] = r+1;
        }
        bool ok = true;
        rep(i,N){
            int tot = 0;
            for(auto v: V[i]) {
                tot += sz[v];
            }
            if(tot != W[i].size()) {
                ok = false;
                break;
            }
        }
        if(!ok) continue;
        vector<string> ans(10, "?");
        rep(i,N) {
            string w = W[i];
            reverse(w.begin(), w.end());
            string t = "";
            for(auto v:V[i]){
                rep(y, sz[v]){
                    t.push_back(w.back());
                    w.pop_back();
                }
                if(ans[v] == "?") ans[v] = t;
                else if(ans[v] != t) {
                    ok = false;
                    break;
                }
                t = "";
            }
        }
        if(!ok) continue;
        rep(i,K) cout << ans[i] << endl;
        break;
    }
    return 0;
}