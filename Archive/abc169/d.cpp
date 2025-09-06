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
    unordered_map<ll, ll> mp;
    for(ll i = 2; i*i <= N; i++) {
        while(N%i == 0) {
            N /= i;
            mp[i]++;
        }
    }
    if(N!=1) mp[N]++;
    int cnt = 0;
    for(auto [m, c] : mp) {
        ll k = 1;        
        while(c > 0) {
            if(c >= k) {
                c-=k;
                cnt++;
            } else {
                break;
            }
            k++;
        }
    }
    cout << cnt << endl;
    return 0;
}