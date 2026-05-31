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
    priority_queue<double,vector<double>,greater<double>> que;
    rep(i,N) {
        double v; cin>>v;
        que.push(v);
    }
    rep(i,N-1) {
        double q1 = que.top();
        que.pop();
        double q2 = que.top();
        que.pop();
        que.push((q1+q2)/2);
    }
    printf("%.10f\n", que.top());
    
    return 0;
}