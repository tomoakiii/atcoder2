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
    vector A(N,vector<ll>(N,-INF));
    vector B(N,vector<ll>(N));
    vector C(N,vector<ll>(N));
    rep(i,N) rep(j,N) cin>>A[i][j];

    rep(i,N) {
        multiset<ll> st;
        rep(j,K) st.insert(-A[i][j]);
        int id=0;
        B[i][id++]=*st.begin();
        for(int j=K;j<N;j++){
            st.erase(st.find(-A[i][j-K]));
            st.insert(-A[i][j]);
            B[i][id++]=*st.begin();
        }
    }
    rep(i,N) rep(j,N) B[i][j]*=-1;
    rep(j,N){
        multiset<ll> st;
        rep(i,K) st.insert(-B[i][j]);
        int id=0;
        C[id++][j]=*st.begin();
        for(int i=K;i<N;i++){
            st.erase(st.find(-B[i-K][j]));
            st.insert(-B[i][j]);
            C[id++][j]=*st.begin();
        }
    }
    rep(i,N) rep(j,N) C[i][j]*=-1;

    vector D(N+1,vector<ll>(N+1,-INF));
    rep(i,N)rep(j,N) D[i+1][j+1]=A[i][j];
    rep(i,N+1)rep(j,N) D[i][j+1]+=D[i][j];
    rep(i,N)rep(j,N+1) D[i+1][j]+=D[i][j];
    ll mx=0,ans=0;
    rep(i,N-K+1) rep(j,N-K+1) {
        int ni=i+K, nj=j+K;
        ll p = D[ni][nj] + D[i][j] - D[ni][j] - D[i][nj] - C[i][j];
        chmax(ans,p);
    }
    cout<<ans<<endl;

    return 0;
}