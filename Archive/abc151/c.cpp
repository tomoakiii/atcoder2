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
    ll N, M;
    cin >> N >> M;
    vector<ll> wa(N+1);
    vector<bool> ac(N+1);
    ll pn = 0;
    ll an = 0;
    rep(i,M) {
        int p; cin>>p;
        string s; cin>>s;
        if(s=="WA") wa[p]++;
        if(s=="AC") {
            if(!ac[p]) {
                ac[p] = true;
                pn += wa[p];
                an++;
            }
        }
    }
    cout << an << " " << pn << endl;
    return 0;
}