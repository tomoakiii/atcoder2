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

set<ll> prime_factorization(ll X){
    set<ll> v;
    
    for(ll x=1; x*x<=X; x++){
        if(X%x == 0) {
            v.insert(x);
            v.insert(X/x);
        }
    }    
    return v;
}

int main(){
    ll N,X;
    cin >> N >> X;
    // auto P = prime_factorization(X);
    vector La(N, vector<ll>{});
    rep(i,N){
        int L; cin>>L;
        rep(j,L) {
            ll a; cin>>a;
       //     if(!P.contains(a)) continue;
            La[i].push_back(a);
        }
    }
    ll ans = 0;
    auto f = [&](auto f, ll x, int p) -> void{
        rep(i,La[p].size()){
            if(x % La[p][i] > 0) continue;            
            if (p<N-1) f(f, x/La[p][i], p+1);
            else if(x/La[p][i] == 1) ans++;
        }
        
    };
    f(f, X, 0);
    cout<<ans<<endl;
    return 0;
}