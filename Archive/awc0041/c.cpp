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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    ll ans=0;
    rep(i,N) {
        ll tgt=K-A[i];
        auto it=lower_bound(A.begin(),A.end(),tgt)-A.begin();
        if(it <= i) it++;
        ans+=N-it;
    }
    cout<<ans/2<<endl;
    return 0;
}