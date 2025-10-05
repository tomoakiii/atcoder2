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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    rep(i,N-1) A[i+1] += A[i];
    int sft = 0;
    while(Q--) {
        int top; cin>>top;
        if(top == 1) {
            int c; cin >> c;
            sft += c;
            sft %= N;
        } else {
            int l, r; cin>>l>>r;
            l--, r--;
            l += sft, r+= sft;
            l%=N; r%=N;
            ll sm = 0;
            if(r<l) {
                sm += A[N-1] - (A[l-1] - A[r]);
            } else {
                if(l-1>=0) sm += A[r] - A[l-1];
                else sm += A[r];
            }
            cout << sm << endl;
        }
    }
    return 0;
}