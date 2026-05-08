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
    ll N,K,G;
    cin >> N >> K >> G;
    vector<ll> A(N);
    ll sm=0;
    fenwick_tree<ll> FT(N);
    rep(i,N) {
        ll D,T; cin>>D>>T;
        sm+=T;
        A[i]=T;
        FT.add(i,T);
    }
    ll mx=0;
    rep(i,N-K){
        chmax(mx, FT.sum(i,i+K));
    }
    cout<<G+sm-mx<<endl;
    return 0;
}