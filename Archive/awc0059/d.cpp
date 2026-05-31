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
    ll N;
    cin >> N;
    string S; cin>>S;
    vector<ll> A(N+1);
    rep(i,N) {
        if(S[i] == 'V') A[i+1]=1;
        if(S[i] == 'F') A[i+1]=-1;
    }
    rep(i,N) A[i+1]+=A[i];
    vector<ll> C(2*N+1);
    ll ans=0;
    C[N] = 1;
    for(int i=1; i<=N; i++) {
        ll tgt = N+A[i];
        ans += C[tgt];
        C[A[i]+N]++;
    }
    cout<<ans<<endl;
    return 0;
}