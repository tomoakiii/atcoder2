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
typedef pair<ll,ll> p;
int main(){
    ll T; cin>>T;
    ll N;
    cin >> N;
    priority_queue<ll, vector<ll>, greater<ll>> que0, que1;
    rep(i,N) {
        ll a; cin>>a; que0.push(a);
    }
    ll M; cin>>M;
    rep(i,M) {
        ll a; cin>>a; que1.push(a);
    }
    ll rm = 0;
    while(!que1.empty()) {
        auto t = que1.top(); que1.pop();
        while(!que0.empty() && t > T+que0.top()) {
            que0.pop();
            continue;
        }
        if(que0.empty() || t < que0.top()) {
            cout << "no" << endl;
            return 0;
        }
        que0.pop();
    }
    cout<<"yes"<<endl;
    return 0;
}