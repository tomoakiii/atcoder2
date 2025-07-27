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
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    vector dp(200, vector<int>{});
    rep(i,N) {
        vector dp_new(200, vector<int>{});
        auto ans = [&](vector<int> &a)->void{
            cout<<a.size()<<" ";
            for(auto p: a) cout<<p<<" ";
            cout<<endl;
        };
        rep(j,200) {
            ll nx = (A[i] + j) % 200;
            if(!dp[j].empty()) {
                if(!dp[nx].empty()) {
                    dp[j].push_back(i+1);
                    cout<<"Yes"<<endl;
                    ans(dp[j]);
                    ans(dp[nx]);
                    return 0;
                } else {
                    dp[nx].push_back(i+1);
                }
            }
        }
        ll a2 = A[i]%200;
        if(dp[a2].empty()) {
            dp[a2].push_back(i+1);
        } else {
            cout<<"Yes"<<endl;
            ans(dp[a2]);
            cout<<1<<" "<<i+1<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}