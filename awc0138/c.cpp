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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),B(N);
    rep(i,N) {
        cin>>A[i]>>B[i];
    }
    ll r=0,sm=0,hap=0;
    ll ans=0;
    rep(i,N){
        if(r<i){
            r=i;
            sm=0;
            hap=0;
        }
        while(r<N && sm+B[r]<=K){
            hap+=A[r];
            sm+=B[r++];
        }
        chmax(ans,hap);
        sm-=B[i];
        hap-=A[i];  
    }
    cout<<ans<<endl;
    return 0;
}