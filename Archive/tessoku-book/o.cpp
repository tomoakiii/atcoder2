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
    ll N; cin>>N;
    map<ll,int> mp;
    vector<ll> A(N);
    priority_queue<ll,vector<ll>,greater<ll>> que;
    rep(i,N) {
        ll a; cin>>a;
        A[i] = a;
        que.push(a);
    }
    int id = 0;
    while(!que.empty()) {
        auto a = que.top();
        que.pop();
        if(!mp.contains(a)) {
            id++;
            mp[a] = id;
        }
    }
    rep(i,N) cout << mp[A[i]] << " ";
    cout << endl;
}