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
    ll X,Y,Z,K;
    cin >> X>>Y>>Z>>K;
    vector<ll> A(X),B(Y),C(Z);
    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i,X) cin>>A[i];
    rep(i,Y) cin>>B[i];
    rep(i,Z) cin>>C[i];
    rep(i,X) rep(j,Y) que.push(A[i]+B[j]);
    while(que.size() > K) que.pop();
    vector<ll> p{};
    while(!que.empty()) {
        p.push_back(que.top());
        que.pop();
    }
    rep(i,Z) rep(k,p.size()) {
        que.push(C[i] + p[k]);
    }
    while(que.size() > K) que.pop();
    deque<ll> ans;
    while(!que.empty()) {
        ans.push_front(que.top());
        que.pop();
    }
    for(auto a:ans) cout<<a<<endl;
    return 0;
}