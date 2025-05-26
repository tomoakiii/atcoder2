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
    priority_queue<pair<ll,int>> que;
    rep(i,N) {
        cin>>A[i];
        que.push({A[i], i});
    }
    vector<ll> sm(N);
    vector<pair<int, int>> visit(N, {-1, N});
    while(!que.empty()) {
        auto [q, i] = que.top();
        que.pop();
        int l = r = i;
        rep(i,N) {
            if (visit[i].first < l) {
                visit[i].first = l
            }
        }

    }
    
    
    return 0;
}