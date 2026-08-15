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


bool is_prime(ll n){
    auto modpowll=[](__int128 a, ll e, ll m)->ll{
        __int128 ret=1;
        while(e){
            if(e & 1) ret = ret * a % m;
            a = a * a % m;
            e /= 2;
        }
        return (ll)ret;
    };
    vector<ll> a_list({2, 3, 5, 7, 11});
    if(n <= 2) return n == 2;
    if(n % 2 == 0) return false;
    ll d = (n-1) / ((n-1)&(1-n));
    for(ll a: a_list){
        ll t = d;
        a = modpowll(a, t, n);
        if(a == 0 || a == 1) continue;
        while(a != n-1){
        t *= 2;
        if(t == n-1) return false;
        a = (ll)((__int128)a * a % n);
        if(a == 1) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll M = 2e6;
    ll T; cin>>T;
    while(T--){
        ll n; cin>>n;
        ll m = 0;
        while(true){
            if(is_prime(n+m)) {
                cout<<m<<endl;
                break;
            }else{
                m++;
                continue;
            }
        }
    }
    return 0;
}