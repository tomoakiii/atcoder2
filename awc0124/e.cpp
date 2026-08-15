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
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    priority_queue<ll,vector<ll>,greater<ll>> que;
    rep(i,N) {
        ll a; cin>>a; ans+=a;
        if(i>0 && i<N-1 && a<0)que.push(a); 
    }
    while(!que.empty() && K--){
        ans -= que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}