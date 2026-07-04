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
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),B(N);
    rep(i,N) cin>>A[i];
    rep(i,N) cin>>B[i];
    vector<ll> C(N),D(N+1);
    rep(i,N) C[i]=B[i]-A[i];
    ll last=0;
    ll ans=0;
    rep(i,N){
        last-=D[i];
        if(C[i]<0 || last>C[i]) {
            cout<<-1<<endl;
            return 0;
        }
        C[i]-=last;
        if(i+K>N)continue;
        ans+=C[i];
        D[i+K]+=C[i];
        last+=C[i];
        C[i]=0;
    }
    rep(i,N) if(C[i]>0) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}