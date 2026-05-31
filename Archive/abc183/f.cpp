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
    vector<ll> C(N);
    rep(i,N) {
        cin>>C[i];
        C[i]--;
    }
    dsu UF(N);
    vector<map<int,int>> grp(N);
    rep(i, N) grp[i][C[i]]++;
    while(Q--){
        int top; cin>>top;
        if(top == 1) {
            int a, b; cin >> a >> b;
            a--,b--;
            if(!UF.same(a, b)) {
                int l1 = UF.leader(a), l2 = UF.leader(b);
                int l = UF.merge(a,b);
                if(l != l1) {
                    for(auto [g, x]: grp[l1]){
                        grp[l][g] += x;
                    }
                    grp[l1].clear();
                } 
                if(l != l2) {
                    for(auto [g, x]: grp[l2]){
                        grp[l][g] += x;
                    }
                    grp[l2].clear();
                }
            }
        } else {
            int x,y; cin>>x>>y;
            x--,y--;
            int l = UF.leader(x);
            cout << grp[l][y] << endl;
        }
    }
    return 0;
}