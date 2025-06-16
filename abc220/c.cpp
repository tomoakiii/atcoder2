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
    ll X;
    cin>>X;
    ll p = X/sm;
    X-=p*sm;
    rep(i,N){
        X-=A[i];
        if(X<0) {
            cout<<p*N+(i+1)<<endl;
            return 0;
        }
    }
    cout<<p*N+(N+1)<<endl;
    return 0;
}