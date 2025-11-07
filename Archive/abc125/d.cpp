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
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    vector<ll> neg, pos;
    ll sm = 0;
    rep(i,N) {
        sm += A[i];
        if(A[i]<0) neg.push_back(A[i]);
        else pos.push_back(A[i]);
    }
    if(neg.size() % 2 == 0) {
        ll ans = 0;
        for(auto a:neg) ans-=a;
        for(auto a:pos) ans+=a;
        cout<<ans<<endl;
    } else {
        priority_queue<ll> que;
        for(auto x:neg) que.push(-x);
        for(auto x:pos) que.push(x);
        ll ans = 0;
        while(que.size() > 1) {
            ans += que.top();
            que.pop();
        }
        ans += -que.top();
        cout<<ans<<endl;
    }

    return 0;
}