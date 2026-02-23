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
typedef modint998244353 mint2;
int main(){
    ll N,Q;
    cin >> N >> Q;
    dsu UF(N+1);
    while(Q--){
        ll l,r;cin>>l>>r;
        l--;
        UF.merge(l,r);
    }
    if(UF.same(0,N))cout << "Yes" << endl;
    else cout<<"No"<<endl;
    return 0;
}