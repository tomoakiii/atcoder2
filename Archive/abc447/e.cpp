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
typedef modint998244353 mint;
int main(){
    ll N, M;
    cin >> N >> M;
    vector<pair<int,int>> UV(M);
    rep(i,M) {
        int u,v;
        cin>>u>>v;
        u--, v--;
        UV[i] = {u,v};
    }
    dsu UF(N), UF2(N);
    ll cnt=0;
    mint ans = 0;
    vector<mint> pow2(M+1,1);
    rep(i,M) pow2[i+1]=pow2[i]*2;
    bool flg = false;
    for(int i=M-1;i>=0; i--) {
        auto [u,v] = UV[i];
        if(!flg){
            if(UF.same(u,v))continue;
            UF.merge(u,v);
            cnt++;
            if(cnt==N-1) {
                flg = true;
            } else{
                UF2.merge(u,v);
            }
        }
        if(flg) {
            if(UF2.same(u,v)) continue;
            ans += pow2[i+1];
        }
    }
    cout << ans.val() << endl;
    return 0;
}