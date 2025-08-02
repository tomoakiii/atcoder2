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
    vector<ll> P(N), A(N), B(N);    
    rep(i,N) cin>>P[i] >> A[i] >> B[i];
    ll M = 1000;
    ll last = P[N-1];    
    ll sm = 0;
    rep(i,N) sm+= B[i];
    vector<ll> dp(M*10000,-1);
    
    rep(i,P[N-1]+1) dp[i] = i + A[N-1];            
    for(int i = P[N-1] + 1; i < M*10000; i++) dp[i] = max((ll)0, i-B[N-1]);
    
    for(int i=N-2; i>=0; i--) {
        vector<ll> dp_new(M*10000,-1);
        rep(j, P[i]+1) {   
            int id = j+A[i];
            dp_new[j] = dp[id];            
        }
        ll last2;
        for(int j = P[i] + 1; j < M*10000; j++) {
            int id = max((ll)0, j - B[i]);
            dp_new[j] = dp[id];
            if(id > last) {
                last2 = j;
                break;
            }
        }
        last = last2;
        swap(dp, dp_new);
    }
    ll Q; cin>>Q;
    while(Q--){
        ll x; cin >> x;
        if(x > last) {
            cout<<x-sm<<endl;
        }else {
            cout<<dp[x]<<endl;
        }
    }

    return 0;
}