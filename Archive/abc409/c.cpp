#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef unsigned long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, L;
    cin >> N >> L;
    map<ll, ll> mp;
    ll c = 0; mp[0]++;
    rep(i,N-1) {
        ll v; cin>>v;
        c+=v;
        c%=L;
        mp[c]++;
    }
    if(L%3 != 0) {
        cout<<0<<endl;
        return 0;
    }
    ll ans = 0;
    ll d = L/3;
    rep(i,d) {
        ll a = i;
        ll b = a + d;
        ll c = b + d;
        if(mp.contains(a) && mp.contains(b) && mp.contains(c)) 
        {
            ans += mp[a] * mp[b] * mp[c];
        }
    }
    cout<<ans<<endl;
    return 0;
}