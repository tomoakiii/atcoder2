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
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N), B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    ll sm = 0;
    vector<int> sel(N);
    rep(i,N) {
        sm += min(A[i], B[i]);
        if(A[i] > B[i]) sel[i] = 1;
    }
    while(Q--) {
        char c;
        ll x, v;
        cin >> c >> x >> v;
        x--;
        if(sel[x] == 1) sm -= B[x];
        else sm -= A[x];
        
        if(c == 'A') A[x] = v;
        else B[x] = v;
        
        if(A[x] < B[x]){                
            sel[x] = 0;
            sm += A[x];
        } else {
            sel[x] = 1;
            sm += B[x];
        }
        cout << sm << endl;
    }

    return 0;
}