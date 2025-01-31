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
    map<ll, ll> mp;
    rep(i,N) {
        cin>>A[i];
        mp[A[i]]++;
    }
    ll ans = 0;
    auto id = mp.end();
    id--;
    ll mx = id->first;
    id = mp.begin();
    while(id != mp.end()) {
        auto id2 = id;
        while(id2 != mp.end()) {
            ll p = id->first * id2->first;
            if(p > mx) break;
            if(mp.contains(p)) {
                if(id->first == p) ans += 1; 
                else if(id->first == id2->first) ans += id->second * (id->second-1) / 2 * mp[p];
                else ans += id->second * id2->second * mp[p];
            }
            id2++;
        }
        id++;
    }
    cout << ans << endl;
    return 0;
}