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
    ll N, X;
    cin >> N >> X;
    vector<ll> A(N), B(N);    
    rep(i,N) cin>>A[i]>>B[i];
    priority_queue<pair<ll, int>> pq;
    pq.push({-A[0]-B[0], 0});
    vector<bool> visit(N, false);
    ll ans = 0;
    bool flg = false;
    while(X-- && !flg){
        auto [t, id] = pq.top();
        pq.pop();
        visit[id] = true;
        ans -= t;
        pq.push({-1*B[id], id});
        
        if(id < N-1 && !visit[id+1]) {                
            pq.push({- A[id+1] - B[id+1], id});
        } else {
            flg = true;
        }    
    }
    if(X > 0) {
        auto [t, id] = pq.top();
        ans -= X * t;
    }
    cout << ans << endl;
    return 0;
}