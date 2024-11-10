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

typedef modint998244353 mint;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<int> A(M);
    rep(i,M) {
        cin>>A[i];
        A[i]--;
    }
    vector<int> TtB(M+1);
    int CP = 0;
    rep(i, M) {
        TtB[i] = CP;
        if (CP == A[i]) {
            CP = A[i]+1;
        } else if (CP == A[i]+1) {
            CP = A[i];
        }
    }
    TtB[M] = CP;
    vector<int> BtT(N);
    rep(i,N) BtT[i]=(i+1);
    vector<int> ans(M);
    for(int i=M-1; i>=0; i--) {
        ans[i] = BtT[TtB[i]];
        swap(BtT[A[i]], BtT[A[i]+1]);        
    }
    rep(i,M) cout<<ans[i]<<"\n";

    return 0;
}