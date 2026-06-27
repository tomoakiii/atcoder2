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
    ll N,M,K;
    cin >> N >> M >> K;

    priority_queue<ll,vector<ll>,greater<ll>> que;
    rep(i,N) {
        ll a; cin>>a; que.push(a);
    }


    ll mx=0;
    rep(i,M) {
        ll p; cin>>p; chmax(mx,p);
    }
    ll ans=0;
    while(!que.empty()){
        auto a = que.top();
        que.pop();
        ll p = (a+mx-1)/mx;
        if(K>=p) {
            K-=p;
            ans++;
        } else {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}