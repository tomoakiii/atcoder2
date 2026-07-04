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
    ll N;
    cin >> N;
    vector<ll> D(N+1);
    vector uv(N+1, vector<ll>{});
    rep(i,N) {
        int p;
        cin>>p>>D[i+1];
        uv[p].emplace_back(i+1);
    }
    ll ans=0;
    auto dfs=[&](auto dfs, int cur)->bool{
        bool flg=false;
        if(D[cur]>0) flg=true;
        ll cnt=0, non=0;
        for(auto nx:uv[cur]){
            if(dfs(dfs,nx)) cnt++;
            else non++;
        }
        if(cnt>non)flg=true;
        if(flg && cur!=0) ans++;
        return flg;
    };
    dfs(dfs,0);
    cout<<ans<<endl;
    return 0;
}