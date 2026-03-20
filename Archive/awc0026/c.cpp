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
    ll N,T,E;
    cin >> N>>T>>E;
    priority_queue<ll,vector<ll>,greater<ll>> que;
    rep(i,N) {
        ll a; cin>>a;
        a*=T;
        que.push(a);
    }
    ll ans= 0;
    while(E && !que.empty()) {
        if(que.top() <= E) {
            E-=que.top();
            que.pop();
            ans++;

        } else {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}