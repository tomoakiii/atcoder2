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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin >> N >> Q;
    vector<ll> A(N),T(N);
    rep(i,N) cin>>A[i]>>T[i];
    vector<ll> B(N+1);
    while(Q--){
        int l,r; ll x;
        cin>>l>>r>>x;
        B[l-1]+=x;
        B[r]-=x;
    }
    rep(i,N)B[i+1]+=B[i];
    ll ans=0;
    rep(i,N){
        if(A[i]+B[i]>=T[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}