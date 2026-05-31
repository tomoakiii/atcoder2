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
typedef modint1000000007 mint;
int main(){
    ll N,K;
    cin >> N >> K;

    ll mx=0;
    ll sm=0;
    rep(i,N) {
        ll l; cin>>l;
        chmax(mx,l);
        sm+=l;
    }
    sm-=mx;
    vector<mint> p2(100,1);
    p2[1]=2;
    for(int i=1;i<99; i++) {
        p2[i+1] = p2[i]*p2[i];
    }
    mint p = 1;
    int id=1;
    while(K) {
        if(K%2==1) p*=p2[id];
        id++;
        K/=2;
    }
    mint ans = mx*p + sm;
    cout<<ans.val()<<endl;
    return 0;
}