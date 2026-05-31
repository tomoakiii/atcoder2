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
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> AB(N);
    rep(i,N) cin>>AB[i].first>>AB[i].second;
    sort(AB.begin(),AB.end());
    priority_queue<ll> que;
    int i = 0;
    ll sm = 0;
    for(ll d=M-1; d>=0; d--){
        ll rem = M-d;
        while(AB[i].first <= rem && i<N) {
            que.push(AB[i++].second);
        }
        if(!que.empty()) {
            sm += que.top();
            que.pop();
        }
    }
    cout<<sm<<endl;
    return 0;
}