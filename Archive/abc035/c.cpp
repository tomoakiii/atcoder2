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
    vector<ll> P(N+1);
    while(Q--) {
        int l,r; cin>>l>>r;
        l--,r--;
        P[l]++; P[r+1]--;
    }
    rep(i,N) P[i+1] += P[i];
    P.pop_back();
    for(auto a:P) cout<<a%2;
    cout<<endl;
    return 0;
}