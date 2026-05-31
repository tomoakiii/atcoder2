#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x7F7F7F7F7F7F7F7F;
const int INFi = 0x7F0F0F0F;

int main(){
    ll N;
    cin >> N;
    vector<ll> ans;
    while(N > 0) {
        if(N==1) {
            ans.push_back(1);
            break;
        }
        N -= 2;
        ans.push_back(2);
    }
    cout << ans.size() << endl;
    for(auto a: ans) cout << a << endl;
    return 0;
}