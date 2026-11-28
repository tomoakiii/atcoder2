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

    ll N, M;
    cin >> N >> M;
    priority_queue<ll> que;
    rep(i,N){
        ll a; cin>>a;
        que.push(a);
    }
    ll ans=0;
    rep(i,INF)rep(j,M){
        auto q=que.top();
        que.pop();
        if(j==0)ans+=q;
        if(que.empty()){
            cout<<ans<<endl;
            return 0;
        }
    }
    return 0;
}