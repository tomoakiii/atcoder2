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
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> B(N),A(N+1);
    rep(i,N) cin>>B[i];
    rep(t, Q){
        int l, r;
        cin>>l>>r;
        l--;
        A[l]+=K; A[r]-=K;
    }
    rep(i,N) {
        A[i+1] += A[i];
    }
    rep(i,N) {
        cout << (A[i]+B[i]) << " \n"[i==N-1];
    }
    return 0;
}