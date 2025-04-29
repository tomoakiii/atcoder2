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
    vector<ll> A(N+1), C(N+M+1), B(M+1);
    rep(i,N+1) cin>>A[i];
    rep(i,N+M+1) cin>>C[i];

    rep(i,N) {
        rep(j,M+1) {
            // A[i]+B[j]=C[i+j]        
            if(i+j<=N+M) B[j] += C[i+j] / A[i];
        }
    }
    for(auto b:B) cout<<b<<endl;
    return 0;
}