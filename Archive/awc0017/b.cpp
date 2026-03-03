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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    rep(i,M) {
        int b; cin>>b;
        b--;
        A[b]++;
        if(b>0) A[b-1]++;
        if(b<N-1) A[b+1]++;
    }
    for(auto a:A) cout<<a<<endl;
    return 0;
}