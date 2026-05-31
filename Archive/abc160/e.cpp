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
typedef pair<ll,int> pli;
int main(){
    ll X,Y,A,B,C;
    cin >> X>>Y>>A>>B>>C;
    vector<ll> P(A),Q(B),R(C);
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll sm = 0;
    rep(i,A) {
        cin>>P[i];        
    }
    rep(i,B) {
        cin>>Q[i];
    }
    rep(i,C) {
        cin>>R[i];
    }    
    sort(P.rbegin(), P.rend());
    sort(Q.rbegin(), Q.rend());
    rep(i,X) {
        que.push(P[i]);
        sm += P[i];
    }
    rep(i,Y) {
        que.push(Q[i]);
        sm += Q[i];
    }
    sort(R.rbegin(), R.rend());
    int ind = 0;
    while(!que.empty()) {
        auto v = que.top();
        que.pop();
        if(R[ind] > v) {
            sm -= v;
            sm += R[ind];
        }
        ind++;
        if(ind == C) break;
    }
    cout << sm << endl;
    return 0;
}