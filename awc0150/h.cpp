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
    deque<ll>A(N);
    rep(i,N){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    vector<ll> B(2*N+1);
    rep(i,N)B[i+1]=B[N+i+1]=A[i];
    rep(i,2*N)B[i+1]+=B[i];
    ll ans=0;
    for(int i=K;i<=2*N;i++){
        chmax(ans,B[i]-B[i-K]);
    }
    cout<<ans<<endl;
    return 0;
}