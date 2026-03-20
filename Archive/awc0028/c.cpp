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
    ll sma=0, smb=0, mx=0, mn=INF;
    vector<ll> A(N),B(N);
    vector<ll> P(N);
    rep(i,N) cin>>P[i];
    rep(i,N) {
        cin>>A[i];
        sma+=A[i];
        chmax(mx, P[i]-A[i]);
        chmax(mn, A[i]);
    }
    rep(i,N) {
        cin>>B[i];
        smb+=B[i];
    }
    cout<<sma+mx-smb<<endl;
    return 0;
}