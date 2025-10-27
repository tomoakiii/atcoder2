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
    vector S(N, vector<int>('z'-'a'+1));
    map<string,ll> mp;
    rep(i,N){
        string s; cin>>s;
        sort(s.begin(),s.end());        
        mp[s]++;
    }
    ll ans = 0;
    for(auto [m, v]: mp) {
        if(v>=2) ans += v*(v-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}