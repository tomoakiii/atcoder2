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
    ll ro = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, N) {
        A[i] += i - ro;
        pq.push(A[i] + i);
        while(!pq.empty()) {
            auto q = pq.top();
            if(q > i) break;
            else {
                ro++;
                pq.pop();
            }
        }
    }
    rep(i, N) {
        cout << max((ll)0, A[i] - (N-i-1)) << " ";
    }
    cout << endl;
    return 0;
}