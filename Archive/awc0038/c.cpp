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
    ll N,L,K;
    cin >> N >> L >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    ll ans=0;
    int cnt=0;
    rep(i,N) {
        cnt++;
        if(L>=A[i]) {
            L-=A[i];
            ans++;
        }
        if(cnt>K) {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}