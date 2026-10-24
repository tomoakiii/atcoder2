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
typedef __uint128_t ut;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K;
    cin >> N >> K;
    if(K>N-1)K=N-1;
    vector<ll> A(N), As(N+1);
    ut ans = 0;
    rep(i,N) {
        cin>>A[i];
    }
    ll mx = 0;
    rep(i,N){
        As[i+1] = As[i] + A[i];
    }
    int l, r;
    for(int i=rem; i<N+1; i++){
        if(i > rem) {
            if(chmax(mx, As[i+K] - As[i])){
                l=i, r=i+K;
            }
        }
    }
    vector<ut> B;
    for(int i=0; i<l; i++){
        B.push_back(A[i]);
    }
    int p = B.size();
    B.push_back(2*mx);
    for(int i=r-1; i<N; i++){
        B.push_back(A[i]);
    }
    while(B.size()>1){
        ll mx = 0, int pre;
        if(p > 0) if(chmax(mx, B[p-1])) pre = i-1;
        if(p < B.size()-1) if(chmax(mx, B[p+1])) pre = i+1;
        5
    }
    cout<<A[0]<<endl;
    return 0;
}