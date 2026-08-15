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
    ll N;
    cin >> N;
    ll P=0, Q=0;

    rep(i,N){
        ll p; cin>>p; p--;
        P=P*10+p;
    }
    rep(i,N){
        ll p; cin>>p; p--;
        Q=Q*10+p;
    }
    vector<ll> ord(N);
    rep(i,N)ord[i]=i;
    ll ans=0;
    do{
        ll X=0;
        rep(i,N){
            X=X*10+ord[i];
        }
        if(P<X && X<Q)ans++;
    }while(next_permutation(ord.begin(),ord.end()));
    cout<<ans<<endl;
    return 0;
}