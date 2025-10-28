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
    ll sm = 0;
    vector<ll> A(N+1),B(N);
    rep(i,N+1) {
        cin>>A[i];
        sm += A[i];
    }
    rep(i,N) {
        cin>>B[i];
        if(B[i] <= A[i]){
            A[i] -= B[i];
        } else {
            B[i] -= A[i];
            A[i] = 0;
            A[i+1] -= B[i];
            if(A[i+1] < 0) A[i+1] = 0;
        }        
    }
    ll sm2 = 0;
    rep(i,N+1) sm2+=A[i];
    cout<<sm-sm2<<endl;
    return 0;
}