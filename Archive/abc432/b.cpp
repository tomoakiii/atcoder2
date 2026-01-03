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
    ll X;
    cin >> X;
    vector<ll> A{};
    while(X) {
        A.push_back(X%10);
        X/=10;
    }
    sort(A.begin(), A.end());

    ll ans = 0;
    for(auto &a:A) {
        if(a != 0) {
            ans = a;
            a = -1;
            break;
        }
    }
    for(auto &a : A) {
        if(a == -1) continue;
        ans *= 10;
        ans += a;
    }
    cout<<ans<<endl;
    return 0;
}