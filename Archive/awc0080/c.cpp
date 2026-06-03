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
    ll N,K;
    cin >> N >> K;
    deque<ll> que;
    ll ans=0;
    rep(i,N) {
        int t; cin>>t;
        ll a; cin>>a;
        if(t==1){
            que.push_back(a);
            sort(que.rbegin(), que.rend());
            while(que.size()>K)que.pop_back();
        } else{
            ans += a;
            if(que.size()>0) {
                ans += que.front();
                que.pop_front();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}