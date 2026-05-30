#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
typedef modint998244353 mint;

void solve(){
    ll N,M;
    cin>>N>>M;
    ll p=1;
    mint ans=0;
    rep(k,20){
        ll lp=p;
        p*=10;
        ll q=p-1;
        ll g=gcd(q,M);
        ll m2=M/g;
        ll cnt = N/m2;
        mint sm=cnt;
        if(q<N){
            sm *= (p-lp);
            ans+=sm;
        }else{
            sm *= (N-lp+1);
            ans+=sm;
            break;
        }
        //cerr<<"[2]"<<" "<<q<<" "<<x<<endl;
    }
    cout<<ans.val()<<endl;
}

int main(){
    ll N;
    cin >> N;
    while(N--){
        solve();
    }
    return 0;
}