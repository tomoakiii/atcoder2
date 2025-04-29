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
    ll N, D;
    cin >> N >> D;
    vector<ll> A(N);
    map<ll, int> mp;
    rep(i,N) {
        cin>>A[i];
        mp[A[i]]++;
    }
    ll ans = 0;
    if(D==0){
        for(auto m:mp) {
            if(m.second>1) ans+=m.second-1;
        }
        cout << ans << endl;
        return 0;
    }

    vector<ll> visit(1E6+1);    
    
    rep(i, 1E6+1) {
        if(visit[i]) continue;
        visit[i] = true;
        if(!mp.contains(i)) continue;
        ll j = i+D;        
        bool flg = false;
        vector<ll> dp(2, INF);
        dp[0] = mp[i];
        dp[1] = 0;
        while(j <= 1E6) {
            visit[j] = true;            
            if(!mp.contains(j)) break;
            vector<ll> dp_new(2, INF);
            dp_new[0] = min(dp[0] + mp[j], dp[1] + mp[j]);
            dp_new[1] = dp[0];
            j+=D;
            swap(dp, dp_new);
        }
        ans += min(dp[0], dp[1]);
    }
    
    cout << ans << endl;


    return 0;
}