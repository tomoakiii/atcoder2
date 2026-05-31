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
    ll p1 = 1;
    rep(i,N) p1*=3;
    rep(i,p1) {
        ll x = i;
        string s;
        rep(j,N) {
            int r = x%3;
            s.push_back('a'+r);
            x/=3;
        }
        reverse(s.begin(), s.end());
        cout<<s<<endl;
    }
    return 0;
}