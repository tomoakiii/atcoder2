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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    sort(A.begin(),A.end());
    ll ans=INF;
    rep(kkk,2) {
        vector<ll> B(N+1);
        rep(i,N)B[i+1]=B[i]+A[i];
        ll sm0=0;
        rep(i,N) {
            ll ed=A[i]+K-1;
            auto it=upper_bound(A.begin(),A.end(),ed)-A.begin();
            ll sm1 = B[N]-B[it];
            ll p = (A[i]*i) - sm0;
            ll cnt=N-it;
            ll q = sm1 - ed*cnt;
            //cerr<<it<<" "<<cnt<<" "<<" "<<sm0<<" "<<sm1<<" "<<p<<" "<<q<<endl;
            chmin(ans,p+q);
            sm0+=A[i];
        }
        reverse(A.begin(),A.end());
        rep(i,N) A[i]=1e9-A[i];
    }
    cout<<ans<<endl;
    return 0;
}