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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,M,Q;
    cin >> N >> M >> Q;
    vector<ll> A(N),C(M),ans(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>C[i];
    while(Q--){
        int p,d; cin>>p>>d;
        p--,d--;
        if(C[d]==0)continue;
        C[d]--;
        ans[d]++;
    }
    for(auto a:ans)cout<<a<<endl;

    return 0;
}