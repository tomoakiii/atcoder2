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
    vector<ll> A(N);
    ll sm = 0;
    rep(i,N) {
        cin>>A[i];
        sm += A[i];
    }
    vector<ll> B(N);
    ll sm2 = 0;
    rep(i,N-1) {
        B[i+1] = 2*A[i] - B[i];
        sm2 += B[i+1];
    }
    ll d = sm - sm2;
    rep(i,N) {
        if(i%2==0) cout<<B[i]+d<<" ";
        else cout<<B[i]-d<<" ";
    }
    cout<<endl;
    return 0;
}