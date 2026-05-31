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
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    rep(i,N) cin>>A[i+1];
    rep(i,N) A[i+1]+=A[i];
    ll mn=0;
    ll mx=-INF;
    rep(i,N){
        ll nw=A[i+1]-mn;
        chmax(mx,nw);
        cout<<mx<<endl;
        chmin(mn,A[i+1]);
    }
    return 0;
}