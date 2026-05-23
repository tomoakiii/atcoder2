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
    ll N,M;
    cin >> N >> M;
    vector<ll> S(N),P(N),A(N+1);
    rep(i,N) cin>>S[i];
    rep(i,N) cin>>P[i];
    rep(i,N) A[i+1]=(S[i]>=P[i])?1:0;
    rep(i,N) A[i+1]+=A[i];
    while(M--){
        int l,r; cin>>l>>r;
        l--,r--;
        if(A[r+1]-A[l] == r-l+1)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}