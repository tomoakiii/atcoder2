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
    ll N,C,T,K;
    cin >> N >> C >> T >> K;
    vector<ll>A(N);
    rep(i,N)cin>>A[i];
    ll ans=0;
    ll sm=0;
    int r=-1;
    rep(l,N){
        if(r+1<l){
            sm=0;
            r=l-1;
        }
        while(r+1<N && C*(sm+A[r+1])<=T){
            r++;
            sm+=A[r]; 
        }
        sm -= A[l];
        if(r-l+1 < K) continue;
        ans += (r-l+2-K);
//        cerr<<l<<" "<<r<<endl;
    }
    cout<<ans<<endl;
    return 0;
}