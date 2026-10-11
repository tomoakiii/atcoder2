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
    ll N,M;
    cin >> N >> M;
    vector<ll> A(M);
    rep(i,M) cin>>A[i];
    vector<ll> B(M+1);
    rep(i,N){
        int l,r; cin>>l>>r; l--;
        ll c;cin>>c;
        B[l]+=c;
        B[r]-=c;
    }
    rep(i,M)B[i+1]+=B[i];
    ll ans=0;
    rep(i,M)if(B[i]>=A[i])ans++;
    cout<<ans<<endl;
    return 0;
}