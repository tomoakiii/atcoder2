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
    ll N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    P--, Q--, R--, S--;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    
    for(int i=P; i<=Q; i++) {
        swap(A[i], A[i-P+R]);
    }
    rep(i,N) cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}