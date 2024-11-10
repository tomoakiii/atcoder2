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
    ll K;
    cin >> K;
    // K = 1E12;
    map<ll, int> mp;
    ll k = K;
    ll i=2;
    while(true){
        while(k%i == 0) {
            mp[i]++;
            k /= i;
        }
        if(i*i > K) break;
        i++;
    }
    if (k!=1) mp[k]++;
    if(mp.size() == 0) {
        cout << K << endl;
        return 0;
    }
    ll cnt = 0;
    for(auto m:mp) {        
        ll k = 0;
        ll tcnt = 0;
        while(k < m.second) {
            tcnt += m.first;            
            ll tt = tcnt;            
            while(tt%m.first == 0) {
                k++;                
                tt /= m.first;
            }            
        }
        chmax(cnt, tcnt);
    }
    cout << cnt << endl;
    return 0;
}