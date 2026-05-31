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

void solve(){
    ll N; cin>>N;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<int> len(N,-1);
    vector<ll> dp(N,INF);
    int mx=0;
    rep(i,N) {
        int id=lower_bound(dp.begin(),dp.end(),A[i])-dp.begin();
        dp[id]=A[i];
        len[i]=id+1;
        chmax(mx,id+1);
    }
    vector<ll> dp2(N,INF);
    vector<int> len2(N,-1);
    for(auto &a:A) a*=-1;
    reverse(A.begin(),A.end());
    rep(i,N) {
        int id=lower_bound(dp2.begin(),dp2.end(),A[i])-dp2.begin();
        dp2[id]=A[i];
        len2[i]=id+1;
    }
    reverse(len2.begin(),len2.end());
    vector<int> ans{};
    rep(i,N){
        if(len[i]+len2[i]-1 == mx) ans.push_back(i+1);
    }
    cout<<ans.size()<<endl;
    for(auto a:ans) cout<<a<<" ";
    cout<<endl;
}

int main(){
    ll T; cin>>T;
    while(T--){
        solve();
    }
    return 0;
}