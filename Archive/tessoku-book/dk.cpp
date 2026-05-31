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
typedef pair<ll, pair<int,int>> pl;
typedef modint1000000007 mint;

int main(){
    ll N; cin>>N;
    string S; cin>>S;
    vector<int> A(N,-1);
    if(S[0] == 'A') A[0] = 0;
    if(S[N-2] == 'B') A[N-1] = 0;
    rep(i,N-2) {
        if(S[i] == 'B' && S[i+1] == 'A') {
            A[i+1] = 0;
        }
    }
    rep(i,N-1) {
        if(A[i+1] == 0) continue;
        if(S[i] == 'A') chmax(A[i+1], A[i] + 1);
    }
    for(int i=N-2; i>=0; i--) {
        if(A[i] == 0) continue;
        if(S[i] == 'B') chmax(A[i], A[i+1] + 1);
    }
    ll ans = 0;
    rep(i,N) {
        ans += A[i]+1;
    }
    cout << ans << endl;
    return 0;
}