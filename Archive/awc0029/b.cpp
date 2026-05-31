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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> V(N);
    rep(i,N) cin>>V[i];

    while(Q--){
        int q; cin>>q;
        if(q==2) {
            int i; cin>>i; i--; cout<<V[i]<<endl;
        } else {
            int a, b; cin>>a>>b;
            a--,b--;
            V[b]+=V[a];
            V[a]=0;
        }
    }
    return 0;
}