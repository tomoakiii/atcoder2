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
    deque<ll> que;
    rep(i,N) {
        ll a; cin>>a;
        if(i%2==0) que.push_back(a);
        else que.push_front(a);
    }
    if(N%2==1) reverse(que.begin(), que.end());
    rep(i,N) cout<<que[i]<<endl;

    return 0;
}