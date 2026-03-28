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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N),D(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>D[i];
    sort(A.begin(),A.end());
    sort(D.begin(),D.end());
    ll ans=0;
    int l=0;
    for(int i=N-M; i<N; i++) {
        ll k = A[i]-D[l++];
        if(k<0) {
            cout<<-1<<endl;
            return 0;
        }
        ans+=k;
    }
    cout<<ans<<endl;
    return 0;
}