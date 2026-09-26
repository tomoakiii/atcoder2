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
    ll N,Q,T;
    cin >> N>>Q>>T;
    vector<ll> A(N+1);
    rep(i,N) cin>>A[i+1];
    rep(i,N)A[i+1]+=A[i];
    while(Q--){
        int l,r; cin>>l>>r;
        ll sm = A[r]-A[l-1];
        if(sm>T)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}