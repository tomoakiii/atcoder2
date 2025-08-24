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
    ll N, Q;
    cin >> N >> Q;
    dsu UF(N);
    vector<int> color(N);
    vector<int> bnum(N);
    while(Q--) {
        int top; cin >> top;
        if(top == 1) {
            int u,v;
            cin>>u>>v;
            u--, v--;
            if(UF.same(u,v)) continue;
            int l1 = UF.leader(u), l2 = UF.leader(v);
            int bn = bnum[l1] + bnum[l2];
            int l3 = UF.merge(u,v);
            bnum[l3] = bn;
        } else if (top == 2) {
            int u; cin >> u; u--;
            int l = UF.leader(u);
            if(color[u] == 0) {
                bnum[l]++;
                color[u] = 1;
            } else {
                bnum[l]--;
                color[u] = 0;
            }
        } else {
            int u; cin >> u; u--;
            int l = UF.leader(u);
            if(bnum[l] > 0) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        
    }
    return 0;
}