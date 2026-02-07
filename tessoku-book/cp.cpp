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
typedef long double ld;
int main(){
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> dp(N,INF);
    dp[0] = 0;
    dp[1] = abs(A[1]-A[0]);
    for(int i=2; i<N; i++) {
        chmin(dp[i], dp[i-1] + abs(A[i]-A[i-1]));
        chmin(dp[i], dp[i-2] + abs(A[i]-A[i-2]));
    }
    vector<int> ans;
    ans.push_back(N-1);
    int cur = N-1;
    while(cur > 0) {
        if(dp[cur - 1] == dp[cur] - abs(A[cur] - A[cur-1])) {
            ans.push_back(cur-1);
            cur--;
        }
        else {
            ans.push_back(cur-2);
            cur-=2;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(auto a:ans) cout<<1+a<<" ";
    cout<<endl;
    return 0;
}