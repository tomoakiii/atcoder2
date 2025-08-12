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
    ll cnt = 0;
    auto jdg = [](ll x, ll p)->bool{
        while(x) {
            if (x % p == 7) return false;
            x /= p;
        }
        return true;
    };


    for(ll i=1; i<=N; i++){
        if (jdg(i, 10) & jdg(i, 8)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}