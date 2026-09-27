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
    map<string,ll> mp;
    rep(i,N){
        string s; cin>>s;
        for(auto &c:s){
            if(c>='A' && c<='Z') c=c-'A'+'a';
        }
        mp[s]++;
    }
    ll ans = 0;
    for(auto [v,c]:mp){
        chmax(ans, c);
    }
    cout<<ans<<endl;
    return 0;
}