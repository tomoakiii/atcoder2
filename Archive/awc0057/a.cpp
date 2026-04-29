#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N,X;
    cin >> N >> X;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    auto B=A;
    for(int i=1;i<N-1;i++) {
        if(A[i-1] == A[i+1] && A[i-1] != A[i]) {
            B[i] = 0;
        }
    }
    for(auto b:B) X=X^b;
    cout<<X<<endl;
    return 0;
}