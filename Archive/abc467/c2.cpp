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
    vector<ll> A(N),B(N-1);
    rep(i,N) cin>>A[i];
    rep(i,N-1) cin>>B[i];
    ll ans2=INF;
    rep(k,2){
        vector<ll> C(N);
        C[0]=k;
        rep(i,N-1){
            if(B[i]==1){
                if(C[i]==1) C[i+1]=0;
                else C[i+1]=1;
            }  else {
                if(C[i]==1) C[i+1]=1;
                else C[i+1]=0;
            }
        }
        ll ans=0;
        rep(i,N){
            ans += abs(A[i]-C[i]);
        }
        chmin(ans2,ans);
    }
    cout<<ans2<<endl;
    return 0;
}