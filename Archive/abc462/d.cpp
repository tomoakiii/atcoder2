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
    ll N,D;
    cin >> N >> D;
    ll M = 2e6;
    vector<ll> A(M);
    rep(i,N) {
        ll s, t; cin>>s>>t;
        t-=D;
        if(t<s) continue;
        A[s]++;
        A[t+1]--;
    }
    rep(i,M-1)A[i+1]+=A[i];
    ll ans=0;
    rep(i,M){
        if(A[i]>1) {
            ans += (A[i] * (A[i]-1))/2;
        }
    }
    cout<<ans<<endl;
    return 0;
}