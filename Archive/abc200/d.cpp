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
    rep(i,N) {
        cin>>A[i];
        A[i]%=200;
    }
    vector dp(200, vector<int>{});    
    rep(i,N) {
        auto ans = [&](vector<int> &a)->void{
            cout<<a.size()<<" ";
            for(auto p: a) cout<<p+1<<" ";
            cout<<endl;
        };
        vector dp_new(200, vector<int>{});

        if(A[i] == 0) {
            rep(j,200) {
                if(!dp[j].empty()) {
                    cout<<"Yes"<<endl;
                    ans(dp[j]);
                    dp[j].push_back(i);
                    ans(dp[j]);
                    return 0;
                }
            }
            dp_new[0].push_back(i);            
            swap(dp, dp_new);
            continue;
        }

        if(!dp[0].empty()) {
            cout<<"Yes"<<endl;
            dp[0].push_back(i);
            ans(dp[0]);
            cout<<1<<" "<<i+1<<endl;
            return 0;
        }

        if(!dp[A[i]].empty()){
            cout<<"Yes"<<endl;
            ans(dp[A[i]]);
            cout<<1<<" "<<i+1<<endl;
            return 0;
        } else {
            dp_new[A[i]].push_back(i);
        }

        rep(j,200) {
            ll nx = (A[i] + j) % 200; 
            if(!dp[nx].empty() && !dp[j].empty()) {
                cout<<"Yes"<<endl;
                ans(dp[nx]);
                dp[j].push_back(i);
                ans(dp[j]);
                return 0;
            }
            if(!dp[j].empty()) {                
                dp_new[nx] = dp[j];
                dp_new[nx].push_back(i);
                dp_new[j] = dp[j];
            }
        }
        swap(dp, dp_new);
    }
    cout<<"No"<<endl;
    return 0;
}