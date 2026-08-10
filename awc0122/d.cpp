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
    ll N,Q;
    cin >> N >> Q;
    vector F(N, vector<string>(N));
    vector<ll> dig10(19,1);
    rep(i,18){
        dig10[i+1] = dig10[i]*10;
    }
    ll func = [](ll x)->ll{
        ll sm = 0;
        while(x){
            sm += x%10;
            x/=10;
        }
        return sm;
    };
    rep(i,N){
        rep(j,i+1){
            string s; cin>>s;
            ll sl = strtoll(s);
            ll mx = func(sl);
            ll p = s[0]-'0';
            ll ln = s.size();
            p *= dig10[ln];
            p--;
            chmax(mx, func(p));
            F[i][j] = mx;
        }
    }
    
    return 0;
}