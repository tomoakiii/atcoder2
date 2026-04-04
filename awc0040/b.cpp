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
    ll M,S;
    cin >> M >> S;
    ll q=S/M;
    ll r=S%M;
    vector<ll> B(M);
    rep(i,M) {
        cin>>B[i];
        if(i<r) B[i]+=q+1;
        else B[i]+=q;
    }
    vector<ll> C(M+1);
    rep(i,M) C[i+1]+=C[i]+B[i];
    ll N; cin>>N;
    rep(i,N) {
        ll l,r;cin>>l>>r;l--;
        cout<<C[r]-C[l]<<endl;
    }
    return 0;
}