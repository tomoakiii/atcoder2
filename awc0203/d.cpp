#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    ll M = 1e6;
    M += 2;
    vector<ll> A(M);
    vector B(M, vector<ll>(2));
    rep(i,N){
        ll a; cin>>a;
        A[a]++;
    }
    for(int i=1;i*i<=M;i++){
        for(int j=i; j*i<=M; j+=i){
            B[i][(j/i)%2] += A[j];
        }
    }
    ll ans=0;
    rep(i,M){
        ans += B[i][0] * B[i][1] * (B[i][1]-1) / 2;
        ans += B[i][0] * (B[i][0] - 1) * (B[i][0] - 2) / 6;
    }
    cout<<ans<<endl;
    return 0;
}