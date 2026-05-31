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
    ll N,M,K;
    cin >> N>>M>>K;
    dsu UF(N);
    vector<int> fnum(N,0);
    rep(i,M) {
        int a, b; cin>>a>>b;
        a--, b--;
        UF.merge(a,b);
        fnum[a]--;
        fnum[b]--;
    }
    
    for(auto gg: UF.groups()){
        for(auto g: gg) {
            fnum[g] += gg.size()-1;
        }
    }
    rep(i,K) {
        int c,d; cin>>c>>d;
        c--,d--;
        if(UF.same(c,d)) {
            fnum[c]--;
            fnum[d]--;
        }
    }
    rep(i,N) {
        cout<<fnum[i]<<" ";
    }
    cout<<endl;
    return 0;
}