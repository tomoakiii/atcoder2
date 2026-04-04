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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    int r=0;
    ll sm=0, ans=0, w=0;
    rep(l,N) {
        while(r<N && w<=K) {
            chmax(ans,sm);
            w+=B[r];
            sm+=A[r];
            r++;
        }
        if(w<=K) chmax(ans,sm);
        w-=B[l];
        sm-=A[l];
    }
    cout<<ans<<endl;
    return 0;
}