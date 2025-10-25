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
    ll T;
    cin >> T;
    ll mxC = 2E8;
    ll mxD = 5E9;
    auto f = [](ll x, ll y)->ll{
        return stoll(to_string(x) + to_string(y));
    };
    while(T--){
        ll C, D; cin>>C>>D;
        ll fmin = f(C, C+1);
        ll fmax = f(C, C+D);
        ll n = sqrtf(fmin);
        ll ans = 0;        
        ll n2 = n*n;
        string sC = to_string(C);
        while(n2 <= fmax) {            
            if(n*n < fmin) {
                n++; n2=n*n;
                continue;
            }
            string s2 = to_string(n2);
            ll c2 = stoll(s2.substr(0, sC.size()));
            string d2s = s2.substr(sC.size(), s2.size() - sC.size());
            if(d2s[0] != '0') {
                ll d2 = stoll(d2s);
                if(c2 == C && d2 >= C+1 && d2 <= C+D) {
                    ans++;
                }
            }
            n++;
            n2 = n*n;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}