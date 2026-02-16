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
typedef pair<ll, pair<int,int>> pl;

int main(){
    ll N,X,Y; cin>>N>>X>>Y;
    vector<ll> A(N);
    rep(i,N) cin>>A[i];
    const ll M = 100000;
    vector<ll> win(2*M,-1);
    queue<ll> que;
    rep(i,X) {
        win[i] = 0;
        que.push(i);
    }
    while(!que.empty()) {
        auto i = que.front();
        que.pop();
        ll me = win[i];
        ll you = (win[i]==1) ? 0 : 1;
        if(i + X <= M) {
            if(win[i+X] == -1) {
                win[i+X] = you;
                que.push(i+X);
            }
        }
        if(i + Y <= M) {
            if(win[i+Y] == -1) {

            }
        }
    }
    return 0;
}