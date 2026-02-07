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
typedef modint1000000007 mint;

int main() {
    int N; cin>>N;
    vector<int> A(N);
    rep(i,N) cin>>A[i];
    vector<int> S(N+1);
    rep(i,N) S[i+1] = S[i] + A[i];
    int Q; cin>>Q;
    while(Q--){
        int L,R; cin>>L>>R;
        int sm = S[R]-S[L-1];
        if(sm*2 == R-L+1) cout<<"draw"<<endl;
        else if(sm*2 > R-L+1) cout<<"win"<<endl;
        else cout<<"lose"<<endl;
    }
    return 0;
}