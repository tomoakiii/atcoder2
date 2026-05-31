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
    int bst = 0;
    for(int i = M; i>=0; i--) {
        ll c = C[N+i];
        for(int j = N-1, st = i+1; j>=0 && st <= M ; j--, st++) {
            c -= A[j] * B[st];
        }
        B[i] = c / A[N];
    }
    for(auto b:B) cout<<b<<" ";
    cout<<endl;
    return 0;
}